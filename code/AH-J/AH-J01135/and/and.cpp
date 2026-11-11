#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200000],maxn=-1,s;
	cin>>n>>m;
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	for(int i=0; i<n-m; i++)
	{
		s=a[i];
		for(int j=i; j<n; j++)
		{
			for(int k=1; k<m; k++)
			{
				s&=a[j+k];
			}
			maxn=max(maxn,s);
			s=a[i];
		}
	}
	cout<<maxn;
	return 0;
}
