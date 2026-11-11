#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q; 
long long t;
vector<int> v[500005];
long long a[500005];
long long f[505][505];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);   cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(f,0x3f3f3f3f3f3f,sizeof(f));
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int j=1;j<=n;j++){
		f[j][j]=0;
		int k;  cin>>k;
		for(int i=1;i<=k;i++){
			int u,vv;
			cin>>u>>vv;
			t=vv;
			v[u].push_back(j);
		}
	}
	for(int i=1;i<=m;i++){
		if(v[i].size()<=1)continue;
		for(int j=0;j<v[i].size();j++){
			for(int l=j+1;l<v[i].size();l++){
				f[v[i][j]][v[i][l]]=2*t;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u,vv;
		cin>>u>>vv;
		long long ans=1e18;
		for(int j=0;j<v[u].size();j++){
			for(int l=0;l<v[vv].size();l++){
				ans=min(ans,a[u]+a[vv]+f[v[u][j]][v[vv][l]]);
			}
		}
		cout<<ans<<"\n";
	}
}

