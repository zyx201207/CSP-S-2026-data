#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,l,r;
ll m,a[N];
ll in()
{
	ll w=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		w=w*10+c-'0';
		c=getchar();
	}
	return w*f;
}
ll ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n;m=in();
	for(int i=1;i<=n;i++) a[i]=in();
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	l=1;r=2;
	ll t=0;
	while(1)
	{
		if(t+ans*(a[r]-a[r-1])>m) 
		{
			t=t+ans*(a[r]-a[r-1])-a[r]+a[l];
			l++,r++;
//			cout<<1<<' '<<l<<' '<<r<<' '<<ans<<' '<<t<<endl;
		}
		else 
		{
			t+=ans*(a[r]-a[r-1]);
			ans=r-l+1;
//			cout<<2<<' '<<l<<' '<<r<<' '<<ans<<' '<<t<<endl;
			r++;
		}
		if(r>n) break;
	}
	cout<<ans;
	return 0;
} 
/*
5 5
4 -1 2 3 2
-1 2 2 3 4
*/
