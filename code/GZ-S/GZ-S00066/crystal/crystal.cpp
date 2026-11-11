//GZ-S00066 刘明远 贵阳市第三实验中学 
#include<bits/stdc++.h>
using namespace std;

int n;
long long m,a[500005];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	long long res=0;
	int ans=1;
	for(int i=2,l=1;i<=n;i++)
	{
		res=res+1ll*(i-l)*(a[i]-a[i-1]);
		while(res>m)
			res-=(a[i]-a[l]),l++;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
