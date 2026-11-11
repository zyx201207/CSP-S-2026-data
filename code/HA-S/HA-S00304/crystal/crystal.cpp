#include<bits/stdc++.h>
using namespace std;
int a[5005];
int b[5005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,sum;
	int maxx=0;
	long long m,m1;
	cin>>n>>m;
	m1=m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m<=100000) 
	{
		for(int i=1;i<=n;i++)
		{
			queue<int>qu;
			sum=0;
			m=m1;
		    for(int j=1;j<=n;j++)
		    {
		    	b[j]=abs(a[i]-a[j]);
			}
			sort(b+1,b+n+1);
			for(int j=1;j<=n;j++)
		    {
		    	qu.push(b[j]);
			}
			while(m>=qu.front())
			{
		    	m=m-qu.front();
				qu.pop();
				sum++;
				if(qu.size()==0)
				{
					break;
				}
			}
			if(maxx<sum)
			{
				maxx=sum;
			}
		}
		cout<<maxx;
	}
	else
	{
		for(int i=1;m-i>=0;i++)
		{
			m=m-i;
			sum++;
			if(m-i<0)
			{
				break;
			}
			m=m-i;
			sum++;
		}
		cout<<sum;
	}
	return 0;
}
