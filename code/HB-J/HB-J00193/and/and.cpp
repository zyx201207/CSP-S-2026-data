#include <bits/stdc++.h>
using namespace std;
long long n2[50]={1};
int n,m;
long long arr[200000],yhh;
bool cmp(long long n,long long m)
{
	return n>m;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0),cout.tie(0);
	for(int i=1;i<=31;i++)
	{
		n2[i]=n2[i-1]*2;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n,cmp);
	yhh=arr[1];
	for(int i=2;i<=m;i++)
	{
		yhh=arr[i]&yhh;
	}
	cout<<yhh;
	return 0;
}
