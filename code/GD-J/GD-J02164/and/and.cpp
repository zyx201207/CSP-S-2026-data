#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	if(n<=2)
	cout<<a[n-1];
	else
	cout<<a[n-2];
	return 0;
 }
