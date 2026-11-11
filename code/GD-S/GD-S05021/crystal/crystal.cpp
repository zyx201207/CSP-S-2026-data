#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005;
int n,m,a[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int cnt=0;
	int c=a[2]-a[1];
	for(int i=1;i<=n;i++)
	{
		if(m-i<0)continue;
		m-=(i*c);
		cnt++;
	}
	cnt++;
	cnt+=(m/cnt);
	cout<<cnt;
	return 0;
}
