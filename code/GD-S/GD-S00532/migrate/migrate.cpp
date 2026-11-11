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

const LL inf=0x3f3f3f3f3f3f3f3fll;

int n;

LL d,arr[N];

int pre[N],suf[N],qzval[N],hzval[N];

int cntpre[N],cntsuf[N];

void solve()
{
	cin>>n>>d;
	
	rep(i,0,n+1) pre[i]=0;
	rep(i,0,n+1) suf[i]=0;
	rep(i,0,n+1) qzval[i]=0;
	rep(i,0,n+1) hzval[i]=0;
	rep(i,0,n+1) cntpre[i]=0;
	rep(i,0,n+1) cntsuf[i]=0;
	
	rep(i,1,n) cin>>arr[i];
	arr[0]=-inf;
	arr[n+1]=inf;
	rep(i,1,n)
	{
		pre[i]=lower_bound(arr+1,arr+n+1,arr[i]-d)-arr;
		++cntpre[pre[i]];
		suf[i]=upper_bound(arr+1,arr+n+1,arr[i]+d)-arr-1;
		++cntsuf[suf[i]];
	}
	rep(i,1,n)
	{
		if(suf[pre[i]]==i && pre[i]!=i)
		{
			qzval[i]+=qzval[pre[i]]-1;
		}
		qzval[i]+=cntsuf[i];
		if(suf[i]==i) --qzval[i];
		qzval[i]+=1;
	}
	per(i,n,1)
	{
		if(pre[suf[i]]==i && suf[i]!=i)
		{
			hzval[i]+=hzval[suf[i]]-1;
		}
		hzval[i]+=cntpre[i];
		if(pre[i]==i) --hzval[i];
		hzval[i]+=1;
	}
//	rep(i,1,n) fpr(i,pre[i],suf[i],qzval[i],hzval[i],cntpre[i],cntsuf[i]);
	LL ans=0;
	rep(i,1,n-1)
	{
		/*
		arr[i] , arr[i+1]
		int x=pre[i],y=suf[i+1];
		if(x!=0 && y!=n+1 && x!=i&&i+1!=y)
		{
			if(suf[x]==i+1&&pre[y]==i)
			{
				ans+=1ll*qzval[x]*hzval[y]-1;
				fpr(i,qzval[x],hzval[y]);
			}
		}
		 i , i+1
		LL cnt1=cntsuf[i+1];
		LL cnt2=cntpre[i];
		if(suf[i]==i+1) --cnt1;
		if(suf[i+1]==i+1) --cnt1;
		if(pre[i+1]==i) --cnt2;
		if(pre[i]==i) --cnt2;
		ans+=1ll*cnt1*cnt2;
		fpr(i,cnt1,cnt2);
		*/
		
		//there would be sth crossing
		
		LL nowpre=0,nowsuf=0;
		int x=pre[i],y=suf[i+1];
		if(x!=0&&x!=i) if(suf[x]==i+1)
		{
			nowpre+=qzval[x]-1;
		}
		if(y!=n+1&&i+1!=y) if(pre[y]==i)
		{
			nowsuf+=hzval[y]-1;
		}
		nowpre+=cntsuf[i+1];
		nowsuf+=cntpre[i];
		if(suf[i]==i+1) --nowpre;
		if(suf[i+1]==i+1) --nowpre;
		if(pre[i+1]==i) --nowsuf;
		if(pre[i]==i) --nowsuf;
		ans+=1ll*nowpre*nowsuf;
//		if(nowpre||nowsuf) fpr(i,nowpre,nowsuf);
	}
	cout<<ans<<'\n';
}

bool Med;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(false),cin.tie(nullptr);
	
	int Tst=clock();
	
	int c,T;cin>>c>>T;while(T--) solve();
	
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
