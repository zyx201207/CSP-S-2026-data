#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],t[N];
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
	sort(a+1,a+n+1);
	int mid=(n+1)/2,ans=0;
	for(int i=1;i<=n;i++)
	{
		t[i]=abs(a[i]-a[mid]);
	}
	sort(t+1,t+n+1);
	for(int i=1;i<=n;i++)
	{
		if(m>=t[i])
		{
			m-=t[i];
			ans++;
		}
		else break;
	}
	cout<<ans;
	return 0;
}
