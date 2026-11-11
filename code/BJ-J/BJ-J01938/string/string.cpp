#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >>n;
	for(int i=1;i<=n;i++)
    {
        cin >>a[i];
        getchar();
        cin >>c[i];
    }
	long long sum=0;
	for(int i=1;i<=n;i++) sum+=a[i];
	if(sum%2!=0)
	{
		long long mid=sum/2+1;
		long long p=0;
		char tag;
		int f;
		for(int i=1;i<=n;i++)
		{
			p+=a[i];
			if(p>=mid)
			{
				tag=c[i];
				f=i;
				p-=a[i];
				break;
			}
		}
		for(int i=n;i>f;i--)
		{
			a[i+1]=a[i];
			c[i+1]=c[i];
		}
		a[f+1]=a[f]-1-(mid-p-1);
		c[f+1]=c[f];
		a[f]=mid-p-1;
		int l=f,r=f+1;
		long long ans=0;
		while(l>0 || r<=n)
		{
			if(a[l]>a[r])
			{
				if(c[l]!=c[r]) ans+=a[r];
				a[l]-=a[r];
				r++;
			}
			else if(a[l]<a[r])
			{
				if(c[l]!=c[r]) ans+=a[l];
				a[r]-=a[l];
				l--;
			}
			else
			{
				if(c[l]!=c[r]) ans+=a[l];
				l--,r++;
			}
		}
		cout <<ans;
	}
	else
    {
        long long mid=sum/2;
		long long p=0;
		char tag;
		int f;
		for(int i=1;i<=n;i++)
		{
			p+=a[i];
			if(p>=mid)
			{
				tag=c[i];
				f=i;
				p-=a[i];
				break;
			}
		}
		for(int i=n;i>f;i--)
		{
			a[i+1]=a[i];
			c[i+1]=c[i];
		}
		a[f+1]=a[f]-(mid-p);
		c[f+1]=c[f];
		a[f]=mid-p;
		int l=f,r=f+1;
		long long ans=0;
		while(l>0 || r<=n)
		{
			if(a[l]>a[r])
			{
				if(c[l]!=c[r]) ans+=a[r];
				a[l]-=a[r];
				r++;
			}
			else if(a[l]<a[r])
			{
				if(c[l]!=c[r]) ans+=a[l];
				a[r]-=a[l];
				l--;
			}
			else
			{
				if(c[l]!=c[r]) ans+=a[l];
				l--,r++;
			}
		}
		cout <<ans;
    }
	return 0;
}
