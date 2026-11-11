#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+5;
int nu[MAXN];
char ch[MAXN];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l,r,lt=1,rt,lc,rc,ans=0;
	cin>>n;
	for (int i=1;i<=n;++i)
	{
		cin>>nu[i]>>ch[i];
	}
	l=nu[1];
	r=nu[n];
	lc=ch[1];
	rc=ch[n];
	rt=n;
	while (lt<rt)
	{
		if (lc!=rc)
		{
			ans+=min(l,r);
		}
		if (l<r)
		{
			r-=l;
			++lt;
			lc=ch[lt];
			l=nu[lt];
		}
		else if (l>r)
		{
			l-=r;
			--rt;
			rc=ch[rt];
			r=nu[rt];
		}
		else 
		{
			++lt;
			lc=ch[lt];
			l=nu[lt];
			--rt;
			rc=ch[rt];
			r=nu[rt];
		}
	}
	cout<<ans;
	return 0;
}
