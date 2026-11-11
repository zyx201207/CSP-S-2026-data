#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e9+5;
long long n,m,a[maxn],sum=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	long long d=a[n]-a[n-1];
	for(int i=n-1;i>=1;i--)
	{
		if(m>=d)
		{
			m-=d;
			a[i]=a[i+1];
		    sum++; 
		    d++;
		}
		else
		{
			continue;
		}
	}
	cout<<sum;
	return 0;
}
