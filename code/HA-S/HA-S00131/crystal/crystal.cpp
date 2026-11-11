#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
#define pir pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
inline int re()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
inline ll rell()
{
	ll x=0;int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
template<typename T> inline void chkmin(T &a,T b){a=min(a,b);}
template<typename T> inline void chkmax(T &a,T b){a=max(a,b);}
const int N=500010;
int n;ll m;
ll a[N],s[N];
bool judge(int l,int r){return a[l]*(r-l+1)-(s[r]-s[l-1])<=m;}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=re();m=rell();
	for(int i=1;i<=n;i++) a[i]=rell();
	sort(a+1,a+1+n,greater<ll>());
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=i,r=n,mid;
		while(l<r)
		{
			mid=(l+r+1)>>1;
			if(judge(i,mid)) l=mid;
			else r=mid-1;
		}
		chkmax(ans,l-i+1);
	}
	printf("%d\n",ans);
	return 0;
}
