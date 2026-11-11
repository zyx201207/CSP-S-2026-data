#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
struct qq
{
	long long d,l,r;
	char c;
}a[N];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    long long s=0;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i].d>>a[i].c;
		a[i].l=a[i-1].r+1;
		a[i].r=a[i].l+a[i].d-1;
	}
	long long len=a[n].r,ln,rn,ll,rr;
	if(len%2==0)
	{
		ln=len/2;
		rn=len/2+1;
	}
	else
	{
		ln=rn=len/2+1;
	}
	for(int i=1;i<=n;i++)
	{
		if(ln>=a[i].l&&ln<=a[i].r)
		{
			ll=i;
		}
		if(rn>=a[i].l&&rn<=a[i].r)
		{
			rr=i;
		}
	}
	if(ll==rr)
	{
		if(ln-a[ll].l+1<=a[rr].r-rn+1)
		{
			rn+=(ln-a[ll].l+1);
			ln-=(ln-a[ll].l+1);
			if(ln-a[ll].l+1==a[rr].r-rn+1)
			{
				rr++;
			}
			ll--;
		}
		else
		{
			ln-=(a[rr].r-rn+1);
			rn+=(a[rr].r-rn+1);
			rr++;
		}
	}
	while(ll>=1&&rr<=n)
	{
		long long sl=ln-a[ll].l+1,sr=a[rr].r-rn+1;
		long long mi=min(sl,sr);
		if(a[ll].c!=a[rr].c)
		{
			s+=mi;
		}
		ln-=mi;
		rn+=mi;
		if(ln<a[ll].l)
		{
			ll--;
		}
		if(rn>a[rr].r)
		{
			rr++;
		}
	}
	cout<<s;
}
