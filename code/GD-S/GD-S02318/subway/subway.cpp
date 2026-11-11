#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define gc getchar
#define pb emplace_back
inline int re(){
	int x=0,f=1; char c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(; isdigit(c);c=gc())x=x*10+(c-48);
	return x*f;
}
constexpr int N = 5e2+3,M = 5e5+3;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

namespace solve{
	int n,m,d,q,k[N];
	ll w[M],f[N][N];
	vector<pii> e[M];
	
	void sol(){
		n=re(); m=re(); d=re(); q=re();
		for(int i=1;i<=m;i++)w[i]=re();
		for(int i=1;i<=n;i++){
			k[i]=re();
			for(int j=1;j<=k[i];j++){
				int x=re(),w=re();
				e[x].pb(pii{i,w});
			}
		}
		memset(f,0x3f,sizeof f);
		for(int i=1;i<=n;i++)f[i][i]=0;
		for(int i=1;i<=m;i++){
			for(int p1=0;p1<e[i].size();p1++)
				for(int p2=0;p2<p1;p2++){
					int pt1=e[i][p1].first; ll w1=e[i][p1].second;
					int pt2=e[i][p2].first; ll w2=e[i][p2].second;
					f[pt1][pt2]=min(f[pt1][pt2],w1+w2);
					f[pt2][pt1]=min(f[pt2][pt1],w1+w2);
				}
		}
		for(int p=1;p<=n;p++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					f[i][j]=min(f[i][j],f[i][p]+f[p][j]);
		while(q--){
			int x=re(),y=re();
			ll ans=INF;
			for(auto tp1:e[x])
				for(auto tp2:e[y]){
					int i=tp1.first,w1=tp1.second;
					int j=tp2.first,w2=tp2.second;
					ans=min(ans,f[i][j]+w1+w2+w[x]+w[y]);
				}
			cout<<ans<<'\n';
		}
	}
}//O(md^2+n^3+qd^2)

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int ID=re(),T=1;
	while(T--)solve::sol();
}

