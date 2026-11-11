#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
int n,m;
int a[N];
int ans=0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int cost=0,j=1,i=1,cnt=1;
	while (i<=n&&j<=n)
	{
		while(j<=n&&(cost+(a[j+1]-a[j])*cnt)<=m){
			int s=a[j+1]-a[j];
			cost+=s*cnt;
			cnt++;
			j++;
		}
		if(j>n)break;
		ans=max(ans,cnt);
		if(j>n)break;
		cost=cost-a[j]+a[i];
		cnt--;
		i++;
	}
	cout<<ans;
	return 0;
}
