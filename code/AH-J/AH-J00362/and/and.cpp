#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1)
	{
		int maxl=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			maxl=max(maxl,a[i]);
		}
		cout<<maxl<<'\n';
	}
	else
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+1+n);
		cout<<a[n-m+1]<<'\n';
	}	
	return 0;
}
