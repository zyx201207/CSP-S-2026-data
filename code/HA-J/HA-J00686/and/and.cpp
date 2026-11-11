#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long sum;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum=a[n];
	for(int i=n-1;i>=m;i--)
	{
		sum&=a[i];	
	}
	cout<<sum;
	return 0;
}
