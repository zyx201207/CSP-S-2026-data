#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n;
struct stru
{
	ll a;
	char c;
	ll l,r;
} x[N];
ll ans;
ll hd,tl,tls,pre,hds;
ll mid,sum;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i].a>>x[i].c;
		x[i].l=sum+1;
		sum+=x[i].a;
		x[i].r=sum;
	}
	mid=(sum+1)>>1;
	hd=1,tl=n;
	tls=pre=sum;
	hds=x[hd].r;
	while(hd<=tl&&tl>=1&&hds<tls)
	{	
		if(x[hd].l>mid) break;
		hds=min(mid,x[hd].r);
		tls=max(mid,tls-(hds-x[hd].l));
		while(tl>=2&&x[tl].l>tls)
		{
			if(x[hd].c!=x[tl].c)
			{
				ans+=pre-x[tl].l+1;
			}
			pre=x[tl-1].r;
			tl--;
		}
		if(x[hd].c!=x[tl].c)
		{
			ans+=pre-tls+1;
		}
		pre=tls-1;
		hd++;
		tls--;
		if(tls<x[tl].l) tl--;
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b


*/
