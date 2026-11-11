#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
long long u;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(m>0)
		{
			for(int j=i-1;j>=1;j--)
			{
				m=m-(a[i]-a[i-j]);
				a[i-j]=a[i];
			}
			if(m==0)
			{
				u=i;
			}
		}
		if(a[i]==a[u])
		{
			u=i;
		}
	}
	cout<<u;
	return 0;
 } 
