#include<bits/stdc++.h>
using namespace std;
long long a[500010],sum[500010],m,mina=LONG_LONG_MAX,maxa=LONG_LONG_MIN;
int n,ans;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],mina=min(a[i],mina),maxa=max(a[i],maxa);
	for(int i=1;i<=n;i++)a[i]-=mina;
	maxa-=mina;
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++)cout<<a[i]<<(i==n?'\n':' ');
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+maxa-a[i];
//	for(int i=1;i<=n;i++)cout<<sum[i]<<(i==n?'\n':' ');
	//calc: sum[r]-sum[l-1]-(maxa-a[r])*(r-l+1)
	int l=1,r=1;
	while(r<=n)
	{
		if(sum[r]-sum[l-1]-(maxa-a[r])*(r-l+1)<=m)
		{
			ans=max(ans,r-l+1);
			r++;
		}
		else
		{
			l++;
		}
		if(l>r)r++;
	}
	cout<<ans;
}
//15:00 is OK 
