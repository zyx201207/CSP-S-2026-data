#include<bits/stdc++.h>
using namespace std;
#define long long int
int n,a[500010],m;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	int i=1,j=1,sum=0,ans;
	while(1)
	{
		if(sum<=m)
		{
			ans=max(ans,j-i+1);
			if(j==n)
			break;
			j++;
			sum+=(j-i)*(a[j]-a[j-1]);
		}
		else
		{
			i++;
			sum-=(a[j]-a[i-1]);
		}
	}
	cout<<ans;
	return 0;
 }
