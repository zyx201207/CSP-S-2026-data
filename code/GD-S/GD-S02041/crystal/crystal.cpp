#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],ans;
void solve1()
{
	for (int i=1;i<=n;i++)
	{
		int cnt=1,used=0;
		for (int j=i-1;j>=1;j--)
		{
			if (m-used>=a[i]-a[j])
			{
				used+=a[i]-a[j];
				cnt++;
			}
			else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
}
void solve2()
{
	int x=max(a[n]-a[n-1],1ll);
	cout<<m/x+1;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if (n>5000) solve2();
	else solve1();
	
	return 0;
} 
