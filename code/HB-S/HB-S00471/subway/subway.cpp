#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll c,n,m,d,q;
ll a[500001];
ll f[501][501];
ll pp[501][500001];
vector<pair<ll,ll>> edges[500001];
pair<ll,ll> b[501];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,-1,sizeof(f));
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=n;i++)
		f[i][i]=0;
	for(int i=1;i<=m;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		ll x,y,z;
		scanf("%lld",&x);
		for(int j=1;j<=x;j++){
			scanf("%lld%lld",&y,&z);
			pp[i][y]=z;
			edges[y].push_back({i,z});
		}
	}
	for(int i=1;i<=m;i++){
		int l=0;
		for(auto y:edges[i]){
			b[++l].first=y.first;
			b[l].second=y.second;
		}
		for(int j=1;j<=l;j++){
			for(int k=j+1;k<=l;k++){
				if(f[b[j].first][b[k].first]!=-1){
					f[b[j].first][b[k].first]=min(f[b[j].first][b[k].first],b[j].second+b[k].second);
					f[b[k].first][b[j].first]=min(f[b[k].first][b[j].first],b[j].second+b[k].second);
				}else{
					f[b[j].first][b[k].first]=b[j].second+b[k].second;
					f[b[k].first][b[j].first]=b[j].second+b[k].second;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==i)
				continue;
			for(int k=1;k<=n;k++){
				if(k==i || k==j)
					continue;
				if(f[i][j]==-1){
					if(f[i][k]!=-1 && f[j][k]!=-1)
						f[i][j]=f[i][k]+f[j][k];
				}else{
					if(f[i][k]!=-1 && f[j][k]!=-1)
						f[i][j]=min(f[i][j],f[i][k]+f[j][k]);
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		ll ans=1e18;
		for(auto yyy:edges[x]){
			for(auto zzz:edges[y]){
				ans=min(ans,f[yyy.first][zzz.first]+a[x]+a[y]+pp[yyy.first][x]+pp[zzz.first][y]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
