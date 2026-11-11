#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>maxn)
		{
			maxn=a[i];
		}
	}
	cout<<maxn;
	return 0;
}
