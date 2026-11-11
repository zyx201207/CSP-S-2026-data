#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k[20005],x,y,dt[20005][25],cnt[20005],b[20005],w[20005];
long long ans;
struct xl{
	int a;
	long long t;
}xl[505][20005];
void dfs(int x,long long sum){
	if(x==y){
		ans=min(sum,ans);
		return;
	}
	for(int i=1;i<=cnt[x];i++){
		if(!b[dt[x][i]]){
			b[dt[x][i]]=1;
			for(int j=1;j<=k[dt[x][i]];j++){
				dfs(xl[dt[x][i]][j].a,sum+xl[dt[x][i]][j].t+xl[dt[x][i]][j].t);
			}
			b[dt[x][i]]=0;
		}
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>xl[i][j].a>>xl[i][j].t;
			dt[xl[i][j].a][cnt[xl[i][j].a]++]=i;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=10000000000;
		dfs(x,y);
		cout<<ans<<'\n';
	}
	return 0;
}

