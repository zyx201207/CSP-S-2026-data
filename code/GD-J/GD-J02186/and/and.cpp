#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],large;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin<<a[i];
		if(a[i]>large)
			large=a[i];
	}
	cout<<large;
	return 0;
 } 
