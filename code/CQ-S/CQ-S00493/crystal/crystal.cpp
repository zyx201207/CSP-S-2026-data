#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,m;

const int M=5e5+5;
int a[M];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	int j=1;
	int sum=0;
	int maxn=0;
	for (int i=1; i<=n; i++)
	{
		sum+=(i-j)*(a[i]-a[i-1]);
		while (sum>m)
		{
			sum-=a[i]-a[j];
			j++;
		}
		maxn=max(maxn,i-j+1);
	}
	cout<<maxn<<"\n"; 
	return 0;
}
