#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,ans,d,a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	{
		d=m;
		cnt=0;
		for(int j=i;j>=1;j--)
		{
			if(d-(a[i]-a[j])>=0)
			{
				d-=a[i]-a[j];
				cnt++;
			}
			else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
