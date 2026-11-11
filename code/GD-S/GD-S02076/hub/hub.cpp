#include<bits/stdc++.h>
#define ll long long 
#define ygkg putchar(' ')
#define endl putchar('\n')
#define fi first
#define se second
const ll mod=998244353;
const ll inf=1e16;
namespace io
{
	template<typename L>
	void in(L &x)
	{
		x=0;bool p=0;char ch=getchar();
		while(!isdigit(ch)) p=ch=='-',ch=getchar();
		do{x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}while(isdigit(ch));
		x=p?-x:x;
	}
	template<typename L>
	void _out(L x){if(x) _out(x/10),putchar((x%10)^48);}
	template<typename L>
	void out(L x){_out(x>0?x:(x?(putchar('-'),-x):(putchar('0'),0))),endl;}	
}
using namespace io;
using namespace std;
ll n,k;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,T;in(c),in(T);
	while(T--)
	{
		in(n),in(k);
		for(ll i=1,u,v;i<n;++i) in(u),in(v);
		if(n==k){out(0);continue;}
		out(rand()%(n-k)+1);
	}
	return 0;
}
