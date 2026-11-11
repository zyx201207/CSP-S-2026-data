#include<iostream>
#include<cstdio>
using namespace std;
int c,n,m,d,q;
long long w[500010];
long long gt[510][510];
int k[510];
int u,v;
int tot;
int a[500010];
long long t[500010];
int nxt[500010];
int haed[500010];
int x,y;
long long ans=1e18;
void addb(int x,int y,int z){
	a[++tot]=y;
	t[tot]=z;
	nxt[tot]=haed[x];
	haed[x]=tot;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<=500;++i){
		for(int j=1;j<=500;++j){
			gt[i][j]=1e18;
		}
		gt[i][i]=0;
	}
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			cin>>u>>v;
			addb(u,i,v);
		}
	}
	for(int k=1;k<=m;++k){
		for(int i=haed[k];i;i=nxt[i]){
			for(int j=nxt[i];j;j=nxt[j]){
				gt[a[i]][a[j]]=min(gt[a[i]][a[j]],t[i]+t[j]);
				gt[a[j]][a[i]]=gt[a[i]][a[j]];
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				gt[i][j]=min(gt[i][j],gt[i][k]+gt[k][j]);
			}
		}
	}
	for(int k=1;k<=q;++k){
		ans=1e18;
		cin>>x>>y;
		for(int i=haed[x];i;i=nxt[i]){
			for(int j=haed[y];j;j=nxt[j]){
				ans=min(ans,t[i]+t[j]+gt[a[i]][a[j]]);
			}
		}
		ans=ans+w[y]+w[x];
		cout<<ans<<'\n';
	}
	return 0;
}
