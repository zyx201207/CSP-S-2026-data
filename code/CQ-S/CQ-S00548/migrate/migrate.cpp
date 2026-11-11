#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<numeric>
#include<cstring>
#include<algorithm>
template<typename T>
inline void read(T& x)
{
	x=0;int f=1;
	char c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-') f=-f;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	x*=f;
}
char asdf[1005];
template<typename T>
inline void write(T x,char dlc='\0')
{
	if(x<0) putchar('-'),x=-x;
	int t=0;
	while(x||(!t)) asdf[t++]=x%10+'0',x/=10;
	while(t--) putchar(asdf[t]);
	if(dlc!='\0') putchar(dlc);
}
#define llt long long
#define pint std::pair<int,int>
#define mp std::make_pair
#define fi first
#define se second
#define vint std::vector<int>
#define pb emplace_back
#define vpint std::vector<std::pair<int,int> >
const int N=2e6+5;
int c,T,n,dp[N],cnt[N],sum[N],dps[N];
llt d,a[N],ans; 
std::set<int>S;
inline bool check1(int l,int r)
{
	dp[r]=0;
	S.clear();
	for(int i=1;i<=r-l+1;++i) cnt[i]=sum[i]=0;
	S.insert(0);cnt[0]=1;dps[r]=1;sum[0]=1;
	for(int i=r-1,R=r;i>=1;--i)
	{
		while(a[R]-a[i]>d)
		{
			if(cnt[dp[R]])
			{
				--cnt[dp[R]];
				sum[dp[R]]-=dps[R];
				if(!cnt[dp[R]]) S.erase(S.find(dp[R]));
			}
			--R;
		}
		dp[i]=*S.begin()+1;
		dps[i]=sum[*S.begin()];
//		write(i,32);write(R,32);putchar(32);write(dp[i],32);write(dps[i],10);
		if(!cnt[dp[i]]) S.insert(dp[i]);
		++cnt[dp[i]];
		sum[dp[i]]+=dps[i];
	}
	return dps[l]==2;
}
inline void solve1()
{
	read(n);read(d);ans=0;
	for(int i=1;i<=n;++i) read(a[i]);
	if(n<=3)
	{
		write(0,10);
		return ;
	}
	for(int l=1;l<=n;++l)for(int r=l+3;r<=n;++r) ans+=check1(l,r);
	write(ans,10);
}
inline void solve2()
{
	read(n);read(d);ans=0;
	for(int i=1;i<=n;++i) read(a[i]);
	if(n<=3)
	{
		write(0,10);
		return ;
	}
	long long e=a[2]-a[1];
//	write(n,32);write(d,32);write(e,10);
	if(d<e*2) write(0,10);
	else write(std::max(0ll,n-d/e*2+1),10);
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(c);read(T);
	if(c<=2) while(T--) solve1();
	else if(c==11||c==12) while(T--) solve2();
	return 0;
}
/*
0
0
259997
259995
86669
0
0
0
7
5
5
0
不好我最后两道题没时间打了只有最基础的暴力会赢吗 
*/

