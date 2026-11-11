#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],num;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n-1;i>=m;i--)
	{
		num=a[n];
		num&=a[i];
	}
	cout<<num;
	return 0;
}
