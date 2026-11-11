#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int x=INT_MAX;
	for(int i=n;i>n-m;i--)
	{
		x=min(a[i],x);
	}
	cout<<x;
}
