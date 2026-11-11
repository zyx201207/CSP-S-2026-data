#include <bits/stdc++.h>
using namespace std;
int n,m,maxn=-0x3f;
int main()
{
  freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[200005];
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++) 
		{
		  maxn=max(maxn,a[i]&a[j]);
		}
	}
	cout<<maxn;
	return 0;
}
