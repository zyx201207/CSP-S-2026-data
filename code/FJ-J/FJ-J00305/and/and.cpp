#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
unsigned long long a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	unsigned long long sum=a[n];
	for(int i=n;i>=n-m+1;i--)
	{
		sum&=a[i];
	}
	cout<<sum;
	return 0;
}
