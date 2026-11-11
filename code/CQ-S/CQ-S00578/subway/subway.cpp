#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FN "subway"
int c,n,m,d,q,u,v;
int k[505],ta,ct[500005],a[500005][21];
ll ans,tt,w[500005],dis[505][505],t[500005][21];
int main(){
	freopen(FN".in","r",stdin);
	freopen(FN".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>ta>>tt;
			ct[ta]++;
			a[ta][ct[ta]]=i;
			t[ta][ct[ta]]=tt;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)dis[i][j]=0x3f3f3f3f3f3f3f3f;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<ct[i];j++){
			for(int k=j+1;k<=ct[i];k++){
				int j2=a[i][j],k2=a[i][k];
				dis[k2][j2]=dis[j2][k2]=min(dis[j2][k2],t[i][j]+t[i][k]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		cin>>u>>v;
		ans=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=ct[u];i++){
			for(int j=1;j<=ct[v];j++){
				ans=min(ans,dis[a[u][i]][a[v][j]]+t[u][i]+t[v][j]);
			}
		}
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return 0;
}
//25min
