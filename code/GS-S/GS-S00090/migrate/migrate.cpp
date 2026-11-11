#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int a[N];
int b[N];
int c,t;
float ans=0;
int sum=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]-a[i-1]>d)
			{
				n=min(n,i);
			}
		}
		for(int i=1;i<=d;i++)
		{
			b[i]=i;
		}
		for(int i=0;i<n;i++)
		{
			if(a[n]-a[i]>d&&n-i>=d)
			{
				ans++;
			}
			
		}
		if(ans/2==0)
		{
			sum++;
		}
		cout<<sum;
	}

	return 0;
} 
