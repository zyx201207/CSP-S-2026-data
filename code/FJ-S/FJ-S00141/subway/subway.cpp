#include<bits/stdc++.h>
using namespace std;
int ans,n,way[1005][1005],t[100005];
void dfs(int x,int y,int far){
	if(x==y){
		ans=max(ans,far);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(way[x][i]==1){
			dfs(i,y,far+t[x]+t[i]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,m,d,q,gate[100005],a[100005];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>gate[i];
	}
	int num;
	for(int i=1;i<=n;i++){
		cin>>num;
		for(int j=1;j<=num;j++){
			for(int k=1;k<=num;k++){
				if(j!=k){
					way[j][k]=1;
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int start,end;ans=0;
		cin>>start>>end;
		dfs(start,end,gate[start]+gate[end]);
		cout<<ans<<endl;
	}
	return 0;
}