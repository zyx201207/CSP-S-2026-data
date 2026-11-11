#include<cstdio>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<iomanip>
#include<vector>
#include<set>
#include<deque>
#include<bitset>
using namespace std;
#define int long long
#define ll long long
#define ull unsigned ll
#define db double
#define ld long db
#define ui unsigned
#define eb push_back
#define pb pop_back
#define mk make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ls i<<1
#define rs i<<1|1
#define fir first
#define sec second
#define wls(x) output(x),putchar(32)
#define wln(x) output(x),putchar(10)

template<class T>void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;!isdigit(c);c=getchar())f|=c==45;
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	x=f?-x:x;
}
template<class T>void output(T x)
{
	if(!x)return putchar(48),void();
	if(x<0)putchar(45),x=-x;
	int sta[50]={},tot=0;
	while(x)sta[++tot]=x%10,x/=10;
	for(int i=tot;i;--i)putchar(sta[i]|48);
}
const int N=500007;
int n,ans;
int m,a[N],s[N];
bool check(int x)
{
	for(int i=1;i<=n-x+1;++i)
	{
		int l=i,r=i+x-1;
		if(1ll*(r-l+1)*a[r]-s[r]+s[l-1]<=m)return true;
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;++i)read(a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
	int l=0,r=n;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	return output(ans),0;
}
