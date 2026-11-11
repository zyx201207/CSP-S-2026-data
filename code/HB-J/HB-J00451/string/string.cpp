#include <bits/stdc++.h>
using namespace std;
unsigned long long n,m;
int a[200010];
char s[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    unsigned long long ans=0,len=0,linshi=0;
    for(unsigned long long i=1;i<=n;i++)
    {
		cin>>a[i]>>s[i];
		len+=a[i];
	}
	unsigned long long l,r,ll,lr,f=0;
    for(unsigned long long i=1;i<=n;i++)
    {
		linshi+=a[i];
		if(linshi>=len/2&&f==0)
		{
			l=i;r=i;
			f=linshi-a[i];
			linshi=0;
		}
	}
    if(len%2==0)
    {
		ll=len/2-f;
		lr=a[l]-ll;
	}
	else
	{
		int sum=a[l]-1;
		ll=len/2-f;
		lr=sum-ll;
		
	}
    if(ll<=0)
	{
		l--;
		ll=a[l];
	}
	if(lr<=0)
	{
		r++;
		lr=a[r];
	}
	if(f+ll<linshi) lr--;
    while(l!=0&&r<=n)
    {

		if(s[l]!=s[r])
		{
			ans+=min(ll,lr);
			
		}
		if(ll>lr)
		{
			ll-=lr;
			r++;
			lr=a[r];
		}
		else
		{
			lr-=ll;
			l--;
			ll=a[l];
		}
	}
	cout<<ans;
    return 0;
}
//Trick||Treat!
