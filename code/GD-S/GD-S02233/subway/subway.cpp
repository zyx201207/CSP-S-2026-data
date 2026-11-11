#include<bits/stdc++.h>
using namespace std;
int cct[100000][20],le[100000],c,n,m,d,q,w[500010],k[510],a[510][510],t[510][510],x,y,ans=1e9;
bool lw[500010];
void dfs(int xx,int cnt,int z){

	if(xx==y){
		ans=min(cnt,ans);
		return;
	}
	for(int i=1;i<=le[xx];i++){
		for(int j=1;j<=k[cct[xx][i]];j++){
			if(!lw[cct[xx][i]]){
				lw[cct[xx][i]]=1;
				dfs(a[cct[xx][i]][j],cnt+t[z][xx]+t[cct[xx][i]][xx],cct[xx][i]);
				lw[cct[xx][i]]=0;
			}
		}
	}
}
int main(){
	freopen("subway1.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			cct[j][++le[j]]=i;
		}
	}
	while(q--){
		lw[x]=1;
		cin>>x>>y;
		for(int i=1;i<=le[x];i++){
			for(int j=1;j<=k[cct[x][i]];j++){
				if(!lw[cct[x][i]]){
					lw[cct[x][i]]=1;
					dfs(a[cct[x][i]][j],0,cct[x][i]);
					lw[cct[x][i]]=0;
				}
			}
		}	
		lw[x]=0;
		cout<<ans;
		ans=1e9;
	}
	return 0;
} 
