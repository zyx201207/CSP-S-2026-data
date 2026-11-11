#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long maxm[200005];
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	maxm[0]=LONG_LONG_MAX;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int e=m;
		while(a[i]>maxm[e-1]) e--;
		for(int i=m;i<e;i++)
		{
			maxm[i]=maxm[i-1];
		}
		maxm[e]=a[i];
	}
	cout<<maxm[m];
	return 0;
}
