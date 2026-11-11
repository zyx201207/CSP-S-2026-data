#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m,a[N],z,t,x;
bool dc=true;
ll cz;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
		if(a[i]==2)cz=a[2]-a[1];
		if(a[i]>2)
		{
			int ls=a[i]-a[i-1];
			if(ls!=cz)dc=false;
		}
	}
	if(dc)
	{
		ll js=0,sj=0;
		while(js<m)
		{
			sj++;
			js+=sj*cz;
		}
		cout<<sj;
		return 0;
	}
    sort(a+1,a+1+n);
    for(ll i=1;i<n;i++)
    {
        z+=a[n]-a[i];
    }
    if(z<=m)
    {
		cout<<n;
		return 0;
	}
    for(ll i=n-1;i>=1;i--)
    {
		ll d=a[i+1]-a[i];
		z-=d*i;
		t=z;
		if(z<=m)
		{
			x=max(x,i);
			break;
		}
		for(ll j=1;j<=i;j++)
		{
			
		    t-=(a[i]-a[j]);
            if(t<=m)
            {
                x=max(x,i-j);
                break;
			}
        }
    }
    cout<<x;
    return 0;
}


