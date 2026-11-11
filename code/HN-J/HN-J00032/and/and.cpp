#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int N=1e6+5;
int a[N],st[N];
int cmp(int s1,int s2)
{
	return s1>s2;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n-m+1;i++)
	{
		int sum=a[i];
		for(int j=i+1;j<=i+m-1;j++)
		{
			sum=(sum&a[j]);
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
//50
