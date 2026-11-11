#include<bits/stdc++.h> 
using namespace std;
long long a[200010];
long long as[200010];
char b[200010];
long long val=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long s;
		char p;
		cin>>s>>p;
		b[i]=p;
		a[i]=s;
		as[i]+=as[i-1]+a[i];
		ans+=s;
	}
	long long g;
	long long v=0;
	long long t=ans/2;
	long long k=n+1;
	for(int i=1;i<=n;i++)
	{
		if(as[i]>=t)
		{
				g=i;
				long long vb=a[g];
				a[g]=t-as[g-1];
				for(int j=n+1;j>=g+2;j--)
				{
					a[j]=a[j-1];
					b[j]=b[j-1];
				}
				a[g+1]=vb/2-1;
				b[g+1]=b[g];
			break;
		}
	}
//	cout<<g<<" "<<k<<endl;
//	for(int i=1;i<=n+1;i++)
//	{
//		cout<<b[i]<<" "<<a[i]<<endl;
//	}
//	cout<<g;
	for(int i=1;i<=g;i++)
	{
		while(a[i]>=a[k])
		{
			if(b[i]==b[k])
			{
				a[i]-=a[k];
				k--;	
			}
			else
			{
				a[i]-=a[k];
				val+=a[k];
				k--;
			}
			if(k<=g)
				break;
		}
		if(k<=g)
				break;
		if(b[i]==b[k])
		{
			a[k]-=a[i];
		}
		else
		{
			a[k]-=a[i];
			val+=a[i];
		}
	}
	cout<<val;
	return 0;
}
