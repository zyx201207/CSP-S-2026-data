#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200001],sum=1;
long long cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[m];
}
