#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=n;i--)
	{
		for(int j=m;j>=m;j--)
		{
			int ii=a[i];
			int jj=a[j];
			cout<<ii and jj;
		}
	}
	return 0;
}
