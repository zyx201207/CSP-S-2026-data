#include<iostream>
#include<string>
using namespace std;
unsigned long long n,a[300000],sum=0,len;
char c[300000];
string s;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%lld%c",&a[i],&c[i]);
	for(int l=1,r=n;;)
	{
		if(c[l]!=c[r]) 
		{
			if(a[l]>a[r])
			{
				sum+=a[r];
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r])
			{
				sum+=a[l];
				a[r]-=a[l];
				l++;
			}
			else if(a[l]==a[r])
			{
				sum+=a[l];
				l++;
				r--;
			}
		}
		else
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				r--;
			}
			else if(a[l]<a[r])
			{
				a[r]-=a[l];
				l++;
			}
			else if(a[l]==a[r])
			{
				l++;
				r--;
			}
		}
		if(l>=r) break;
	}
	cout<<sum;
	return 0;
}
