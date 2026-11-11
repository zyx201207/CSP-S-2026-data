#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;

int n;
long long a[200005];
char b[200005];
int l,r;
long long ans=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=1;r=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	while(l<r)
	{
		if(b[r]!=b[l])
		{
			if(a[l]>a[r])
			{
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}
			else if(a[r]>a[l])
			{
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}
			else
			{
				ans+=a[l];
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
			else if(a[r]>a[l])
			{
				a[r]-=a[l];
				l++;
			}
			else
			{
				l++;
				r--;
			}
		} 
		
	}
	cout<<ans<<endl;
	return 0;
} 
