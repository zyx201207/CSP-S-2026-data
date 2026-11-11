#include<bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define For(i,l,r) for(int i=(l);i<=(r);i++)
#define Rof(i,l,r) for(int i=(l);i>=(r);i--)
namespace solve1
{
	int n,m,ans;
	vector<ll> a;
	void mian()
	{
		
	}
}
namespace solve2
{
	const int MAXN=1e4+5,INF=0x3f3f3f3f;
	int n,m,ans;
	bool t[MAXN][MAXN];
	vector<ll> a;
	void dfs(int x,int s,int siz)
	{
		if(t[x][siz]==1) ans++;
		else t[x][siz]=1;
		For(i,x+1,n) if(a[i]-a[x]<=m) dfs(i,s,siz+1);
	}
	void sol()
	{
		cin>>n>>m,a.resize(n+1);
		For(i,1,n) cin>>a[i];
		For(i,1,n)
		{
			memset(t,0,sizeof(t));
			dfs(i,i,0);
		}
		cout<<ans<<'\n',ans=0;
	}
	void mian()
	{
		int _;cin>>_;
		while(_--) sol();
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c;cin>>c;
	if(c==11||c==12) solve1::mian();
	else solve2::mian();
	return 0;
}
