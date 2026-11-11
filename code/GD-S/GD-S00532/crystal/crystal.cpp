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
using pii=pair<int,int>;
using tiii=tuple<int,int,int>;
using tiiii=tuple<int,int,int,int>;
using vi=vector<int>;

template<typename T> void _fpr(T v){cerr<<v<<'\n';}
template<typename T,typename... Args> void _fpr(T v,Args... args){cerr<<v<<' ';_fpr(args...);}
#define fpr(...) cerr<<"[on line "<<__LINE__<<"] ",_fpr(__VA_ARGS__)

const int N=2000010;

int n;

LL m,arr[N],qz[N];

void solve()
{
	cin>>n>>m;
	rep(i,1,n)
	{
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	rep(i,1,n)
	{
		qz[i]=qz[i-1]+arr[i];
	}
	LL ans=0;
	rep(i,1,n)
	{
		int l=1,r=i,mid=0;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(arr[i]*(i-mid+1)-(qz[i]-qz[mid-1])<=m)
			{
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
//		fpr(i-l+1);
		ans=max(ans,i-l+1);
	}
	cout<<ans<<'\n';
}

bool Med;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
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
