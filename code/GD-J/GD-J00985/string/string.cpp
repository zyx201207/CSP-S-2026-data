#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	vector<long long> x(1,-1);
	vector<char> a(1,' ');
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long j;char k;
		cin>>j>>k;
		if(k==a[i-1])
		{
			x[i-1]+=j;
			n--;
			i--;
		}
		else
		{
			x.push_back(j);
			a.push_back(k);
		}
	}
	long long cnt=0;
	for(long long i=0;i<n/2;i++)
	{
		if(a[i+1]==a[n-i])
		{
			if(x[i+1]==x[n-i])
			{
				continue;
			}
			else
			{
				long long num=x[i+1]-x[n-i];
				bool f=(num>0);
				cnt+=abs(num);
				if(f)
				{
					x[i+2]+=num;
				}
				else
				{
					x[n-i-1]+=abs(num);
				}
			}
		}
		else
		{
			if(x[i+1]==x[n-i])
			{
				cnt+=x[i+1];
			}
			else
			{
				cnt+=max(x[i+1],x[n-i]);
				if(x[i+1]>x[n-i])
				{
					x[i+2]+=x[i+1]-x[n-i];
				}
				else
				{
					x[n-i-1]+=abs(x[i+1]-x[n-i]);
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
