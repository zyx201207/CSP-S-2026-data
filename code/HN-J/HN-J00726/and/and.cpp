#include <bits/stdc++.h>
using namespace std;
long long a[10000000000000000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("amd.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++);
	{
		cin>>a[i];
		int Maxx=a[0];
		for(int j=1;j<n;j++)
		{
			Maxx&=a[j];
		}
		cout<<Maxx;
	}
	return 0;
}
