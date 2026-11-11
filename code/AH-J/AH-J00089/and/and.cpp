#include<bits/stdc++.h>
using namespace std;
long long int m,n,a[200005],sum;
bool cmp(long long int x,long long int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,cmp);
	if(m==1)
	{
		cout<<a[1];
		return 0;
	}
	else if(m==n)
	{
		sum=a[1];
		for(int i=2;i<=n;i++)
		sum=sum&a[i];
		cout<<sum;
		return 0;
	}
	sum=a[1];
	for(int i=2;i<=m;i++)
		sum=sum&a[i];
	cout<<sum;
	return 0;
}
