#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,t,xx,yy;
int ans;
int p[500005],q[5005][5005],flag[5005][5005];
void dfs(int x,int s){
	if(x==yy){
		ans=min(ans,s);
		return;
	}
	for(int i=x+1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(flag[j][i]==1&&flag[j][x]==1){
				dfs(i,s+q[i][j]+q[x][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>t;
	for(int i=1;i<=m;i++)
		cin>>p[i];
	int k,x;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x;
			cin>>q[x][i];
			flag[i][x]=1;
		}
	}
	while(t--){
		cin>>xx>>yy;
		ans=99999999;
		dfs(xx,p[xx]+p[yy]);
		cout<<ans<<endl;
	}
	return 0;
}
