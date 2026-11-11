#include <bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	long long a[200050],sum;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	sum=a[1];
	for(int i=2;i<=m;i++)
		sum=(sum&a[i]);
	cout<<sum;
}
