#include<bits/stdc++.h>
using namespace std;
priority_queue<long long,vector<long long>,greater<long long>> q;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	long long m;
	cin>>n>>m;
	long long d;
	long long c=0;
	bool flag=true;
	for(long long i=1;i<=n;i++)
	{
		long long a;
		cin>>a;
		if(i==1)
		{
			d=a;
		}
		else
		{
			if(i==2)
			{
				c=a-d;
				d=a;
			}
			else
			{
				if((a-d)!=c)
				{
					flag=false;
				}
				else
				{
					d=a;
				}
			}
		}
		q.push(a);
	}
	long long ans=0;
	if(flag==true)
	{
		long long num=0;
		while(m>=0)
		{
			num+=c;
			m-=num;
		}
		ans=num;
		if(ans>=n)
		{
			ans=n;
		}
	}
	else
	{
		while(m>=0)
		{
			long long num=0;
			long long a=q.top();
			q.pop();
			long long b=q.top();
			while(b==a)
			{
				q.pop();
				b=q.top();
				num++;
			}
			ans=max(ans,num+1);
			m-=(num+1)*(b-a);
			for(long long i=1;i<=num+1;i++)
			{
				q.push(b);
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
