#include <bits/stdc++.h>
using namespace std;
int n,m;
int num[200000];
long long maxsum=0;
void a(int l,int r)
{
	long long sumnum=num[l];
	for(int i=l+1;i<r;i++)
	{
		sumnum=sumnum&num[i];
	 } 
	 maxsum=max(maxsum,sumnum);
	 return;
}
int main()
{
	froepen(and.in;"r";stdin);
	freopen(and.out;"w";stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	for(int i=0;i<n-m+1;i++)
	{
		a(i,i+m-1);
	cout<<maxsum;
	return 0;
	}
}
