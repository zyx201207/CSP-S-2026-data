#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[25],maxn=-1;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];		
	for(int i=1;i<=n-m+1;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j;k<=j+m-2;k++)
				maxn=max(maxn,a[k]&a[k-1]);
	cout<<maxn;
	return 0;
}
