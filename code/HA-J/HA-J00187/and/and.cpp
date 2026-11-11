#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=200005;
LL n,m,ans;
LL a[N];
LL dp[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	LL maxx=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<LL>());
	ans=a[1];
	for(int i=2;i<=m;i++)
	{
		ans&=a[i];
	}
	cout<<ans<<' ';
	
	return 0; 
} 
