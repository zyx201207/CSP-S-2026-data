#include <Bits/stdc++.h>
using namespace std;
int  n,sum=0;
long long num[200000],c[2000000];
long long st[50000000000000];
int cnt=0,cmt=0;
int main()
{
	freopen(string.cpp,"r",stdin);
	freopen(string.out;"w";stdout);
	for(int i=0;i<n;i++)
	{
		cin>>num[i]>>c[i];
		sum+=num[i];
	}
	for(int i=0;i<n;i++)
	{
		fill(st+cmt,st+cmt+num[i],c[1]);
		cmt+=num[i];
	}
	for(long long i=0;i<=sum;i++)
	{
		if(st[i]!=st[sum-1-i])
			cnt++;
	}
	cout<<cnt;
	return 0;
}
