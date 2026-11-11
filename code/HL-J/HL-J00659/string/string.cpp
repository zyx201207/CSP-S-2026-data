#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	ll n,a[200010]={},ans=0;
	char c[200010]={};
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	ll l=1,r=n;
	ll ls=a[1],rs=a[n];
	while(l<r)
	{
		ll t=min(ls,rs);
		if(c[l]!=c[r])
		{
			ans+=t;
		}
		ls-=t;
		rs-=t;
		if(!ls)
		{
			l++;
			ls+=a[l];
		}
		if(!rs)
		{
			r--;
			rs+=a[r];
		}
	}
	cout<<ans;
    return 0;
}

