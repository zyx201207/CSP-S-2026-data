#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define ref(i,a,b) for(int i=a;i>=b;--i)
#define rek(i,a,b) for(int i=a;i<b;++i)
#define Tie cin.tie(0)->sync_with_stdio(false)
using namespace std;
const int N=2e5+5;
int T,n,m,l,r,ans;
struct Node
{
	int x;
	char c;
}a[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	Tie,cin>>n,l=1,r=n;
	rep(i,1,n) cin>>a[i].x>>a[i].c;
	while(l<r)
	{
		if(!a[l].x)
		{
			++l;
			continue;
		}
		if(!a[r].x)
		{
			--r;
			continue;
		}
		int t=min(a[l].x,a[r].x);
		if(a[l].c!=a[r].c) ans+=t;
		a[l].x-=t,a[r].x-=t;
	}
	cout<<ans;
	return 0;
}//100pts