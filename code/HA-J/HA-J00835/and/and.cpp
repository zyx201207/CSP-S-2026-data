#include<bits/stdc++.h>
using namespace std;
int n,m,x=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n+5];
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	x=a[n-1];
	for(int i=1,j=n-1;i<m;i++,j--)
	{
		x=(x&a[j-1]);
	}
	cout<<x;
	return 0;
}
