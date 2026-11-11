#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ir(i,a,b) for(int i=b;i>=a;i--)
#define inr(L,R,l,r) (l<=L and R<=r)
#define ofr(L,R,l,r) (L>r or l>R)
#define re return
#define ll long long
#define ull unsigned long long
#define ioo cin.tie(0)->sync_with_stdio(0);cout.tie(0)->sync_with_stdio(0);
using namespace std;
const int maxn=5e5+114;

int n,m,d,q;
ll w[maxn];
vector<int> R[maxn];
vector<ll> W[maxn];
ll G[514][514];
int main()
{
	ioo;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T;
	cin>>T>>n>>m>>d>>q;
	rep(i,1,m)
	{
		cin>>w[i];
	}
	rep(i,1,n)
	{
		int k;
		cin>>k;
		rep(j,1,k)
		{
			int a,t;
			cin>>a>>t;
			R[a].push_back(i);
			W[a].push_back(t);
		}
	}
	rep(i,1,n) rep(j,1,n) G[i][j]=1e16;
	rep(i,1,m)
	{
		rep(j,0,(int)R[i].size()-1)
		{
			rep(k,j+1,(int)R[i].size()-1)
			{
				int u=R[i][j],v=R[i][k];
				G[u][v]=min(G[u][v],1ll*W[i][j]+W[i][k]);
				G[v][u]=min(G[v][u],1ll*W[i][j]+W[i][k]);
			}
		}
	}
	rep(i,1,n) G[i][i]=0;
	rep(k,1,n) rep(i,1,n) rep(j,1,n) G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
	rep(i,1,q)
	{
		int u,v;
		cin>>u>>v;
		ll ans=1e17;;
		rep(j,0,(int)R[u].size()-1)
		{
			rep(k,0,(int)R[v].size()-1)
			{
				ans=min(ans,w[u]+w[v]+W[u][j]+W[v][k]+G[R[u][j]][R[v][k]]);
			}
		}
		cout<<ans<<'\n';
	}
}

