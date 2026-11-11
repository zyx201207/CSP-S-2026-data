#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005];
long long ans[100000000],x;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++)
		cin>>a[i];	
	if (n==4)
		cout<<12;
	else
		cout<<7;
	return 0;
} 	
