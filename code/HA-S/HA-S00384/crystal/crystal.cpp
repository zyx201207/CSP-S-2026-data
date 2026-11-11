#include<iostream>
#include<deque>
#include<stdio.h>
#include<algorithm>
using namespace std;
long long n;
long long m;
long long a[1000000];
long long sum=0;
int ans=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	deque<long long> l;
	for(int i=1;i<=n;i++)
	{
		while(!l.empty()&&l.size()*a[i]-sum>m)
		{
			long long f=l.front();
			l.pop_front();
			sum-=f;
		}
		l.push_back(a[i]);
		sum+=a[i];
		int ans1=l.size();
		ans=max(ans,ans1);
	}
	cout<<ans;
	return 0;
}
