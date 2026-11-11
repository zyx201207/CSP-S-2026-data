#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
inline int read()
{
	char c=getchar();int f=1,x=0;
	while(c<'0' || c>'9') {(c=='-')?(f=-1):0;c=getchar();}
	while(c>='0' && c<='9') {x=x*10+(c-'0');c=getchar();}
	return x*f;
}

const int inf=0x3f3f3f3f3f3f3f3f;
const int N=5e5+5;
int n,m,a[N],pre[N];

bool check(int x)
{
	for(int i=1;i+x-1<=n;i++)
		if(a[i+x-1]*x-(pre[i+x-1]-pre[i-1])<=m) return 1;
	return 0;
}

signed main()
{
	fastio;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int l=0,r=n,mid,ans;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	return cout<<ans<<'\n',0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
