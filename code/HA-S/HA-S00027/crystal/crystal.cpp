#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],sum;
int main()
{
	freopen("crystal","r",stdin);
	freopen("crystal","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n;i++)
	{
		
		cin>>a[i];
		int sum=0;
		for(int i=1;i<=m;i++)
		{
			a[i]+1;
			if(a[i]==a[i+1])
			{
				sum++;
			}
		}
	}
	cout<<sum;
}
