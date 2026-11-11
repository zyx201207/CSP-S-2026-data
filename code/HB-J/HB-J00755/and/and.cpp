
#include <bits/stdc++.h>
int n,m,lop;
long long a[100005];
using namespace std;
int main()
{
	freopen("r","and.in",stdin);
	freopen("w","and.out",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	lop=a[n];
	for(int i=n-1;i>n-m;i--)
		lop&=a[i];
	cout<<lop;
	return 0;
}

