#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],sum=1;
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	sum=a[n];
	for(int i=n-1;i>=n-m+1;i--) 
	{
		sum&=a[i];
	}
	cout<<sum;
	return 0;
}
