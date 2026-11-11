#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,zong=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int j=n+1;
	
	for(int i=0;i<n/2+1;i++)
	{
		j--;
		
		if(c[i]!=c[j]&&a[i]==a[j])
		{
			zong+=a[i];
		}
		else if(c[i]!=c[j]&&a[i]>a[j])
		{
			zong+=a[j];
			a[i+1]+=a[i]-a[j];
			
		}
		else if(c[i]!=c[j]&&a[i]<a[j])
		{
			zong+=a[i];
			a[j-1]+=a[j]-a[i];
			
		}
		else if(c[i]==c[j]&&a[i]>a[j])
		{
			zong+=a[i]-a[j];
			a[j-1]-=a[i]-a[j];
			j++;
		}
		else if(c[i]==c[j]&&a[i]<a[j])
		{
			zong+=a[j]-a[i];
			a[i+1]-=a[j]-a[i];
			i--;
		}
		
	}
	cout<<zong;
}
