#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[10000000],b[10000000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=1;i<=n;i++)
		b[n-i+1]=a[i];
	cout<<b[m];
	return 0;
} 
