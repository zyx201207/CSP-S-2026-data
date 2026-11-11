#include <bits/stdc++.h>
using namespace std;
long long n,m;
int a[200000+10];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1);
	long long h=a[n];
	for(int i=n-1;i>n-m;i--)	h=(h&a[i]);
	cout<<h;
	return 0;
} 
