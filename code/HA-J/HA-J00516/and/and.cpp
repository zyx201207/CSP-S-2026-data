#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int b=a[i]&a[i+1];
		maxn=max(maxn,b);
	}
	cout<<maxn;
	return 0;
}
