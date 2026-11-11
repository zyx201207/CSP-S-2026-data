#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],maxv=-1e9,maxx;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		maxv=max(maxv,a[i]);
	}
	if(m==1) cout<<maxv;
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				maxx=max(maxx,a[i]&a[j]);
			}
		 } 
	}
	cout<<maxx;
	return 0;
 } 
/*
4 2
3 15 12 12 


*/
