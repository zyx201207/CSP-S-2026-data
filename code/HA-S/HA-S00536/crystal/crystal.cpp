#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],b[N],sumb[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n-1;i>=1;i--)
	{
		b[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sumb[i]=sumb[i-1]+b[i];
	}
	int ans=1,tmp=m,cnt=1;
	for(int i=n;i>=2;i--)
	{
		while(i-cnt>0)
		{
			if(tmp<sumb[i-1]-sumb[i-cnt-1])
			{
				break;
			}
			tmp-=sumb[i-1]-sumb[i-cnt-1];
			cnt++;
		}
		ans=max(ans,cnt);
		tmp+=(cnt-1)*b[i-1];
		cnt--;
	}
	cout<<ans;
	return 0;
}
