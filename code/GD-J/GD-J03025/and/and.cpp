#include<bits/stdc++.h>
using namespace std;
priority_queue<long long> q;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	long long sum;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		q.push(x);
	}
	for(int i=1;i<=m;i++)
	{
		if(i==1)
		{
			sum=q.top();
			q.pop();
		}
		else
		{
			int a=q.top();
			q.pop();
			sum=sum&a;
		}
	}
	cout<<sum;
	return 0;
}
