#include<bits/stdc++.h>

using namespace std;

namespace LHY
{

#define rep(i,s,t) for(long long i=(s);i<=(t);++i)
#define per(i,t,s) for(long long i=(t);i>=(s);--i)
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mtp make_tuple
#define fi first
#define se second

bool Mst;

using LL=long long;
using LD=long double;
using ULL=unsigned long long;
using pii=pair<long long,long long>;
using tiii=tuple<long long,long long,long long>;
using tiiii=tuple<long long,long long,long long,long long>;
using vi=vector<long long>;

template<typename T> void _fpr(T v){cerr<<v<<'\n';}
template<typename T,typename... Args> void _fpr(T v,Args... args){cerr<<v<<' ';_fpr(args...);}
#define fpr(...) cerr<<"[on line "<<__LINE__<<"] ",_fpr(__VA_ARGS__)

const int N=1000010;

const LL inf=0x3f3f3f3f3f3f3f3fll;

int c,n,m,d,q;

LL othpval[N];

LL mindis[510][510];

vector<pii> e[N],f[N];

/*
e <-> f
*/

void solve()
{
	cin>>c>>n>>m>>d>>q;
	rep(i,1,m)
	{
		cin>>othpval[i];
	}
	rep(i,1,n)
	{
		int k;cin>>k;
		rep(lol,1,k)
		{
			LL x,t;cin>>x>>t;
			e[x].eb(i,t);
			f[i].eb(x,t);
		}
	}
	
	rep(i,1,n) rep(j,1,n)
	{
		mindis[i][j]=inf;
	}
	rep(i,1,n) mindis[i][i]=0;
	
	rep(i,1,n)
	{
		for(auto o1:f[i])
		{
			LL to1,v1;
			tie(to1,v1)=o1;
			for(auto o2:e[o1.fi])
			{
				LL to2,v2;
				tie(to2,v2)=o2;
				mindis[i][to2]=min(mindis[i][to2],v1+v2);
				mindis[to2][i]=min(mindis[to2][i],v1+v2);
			}
		}
	}
	
	rep(k,1,n)
	{
		rep(i,1,n)
		{
			rep(j,1,n)
			{
				mindis[i][j]=min(mindis[i][j],mindis[i][k]+mindis[k][j]);
			}
		}	
	}
	
	rep(lol,1,q)
	{
		int x,y;cin>>x>>y;
		LL ans=inf;
		for(auto to1:e[x]) 
		{
			for(auto to2:e[y])
			{
				ans=min(ans,mindis[to1.fi][to2.fi]+to1.se+to2.se);
			}
		}
		cout<<ans+othpval[x]+othpval[y]<<'\n';
	}
}

bool Med;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false),cin.tie(nullptr);
	
	int Tst=clock();
	
	solve();
	
	int Ted=clock();
	
	cerr<<"T:"<<1.0*(Ted-Tst)/CLOCKS_PER_SEC<<'\n';
	cerr<<"M:"<<(&Mst-&Med)/1024.0/1024.0<<'\n';
	
	return 0;
}

}

int main()
{
	return LHY::main();
}
