#include <bits/stdc++.h>
using namespace std;
int n,m,a[100005],maxn=0;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			maxn=max(maxn,a[j-1]&a[j]);
		}
	}
	cout<<maxn;
	return 0;
}
