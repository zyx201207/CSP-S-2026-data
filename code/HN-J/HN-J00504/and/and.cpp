#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5+5;
int a[N]; 
signed main()// No AC
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	int ans=a[n];
	int idx=0;
	for(int i=n-1;i>=n-m+1;i--)
	{
		while((ans&a[i-idx])==0) idx++;
		if(i-idx<1)
		{
			cout<<0;
			return 0;
		}
		ans&=a[i-idx];
	}
	cout<<ans;
	return 0;
}

