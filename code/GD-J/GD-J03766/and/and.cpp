#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=i;j++)
		{
			if(a[j]>a[j+1])
			   swap(a[j],a[j+1]);
		}
	}
	cout<<a[n-m+2];
	return 0;
}
