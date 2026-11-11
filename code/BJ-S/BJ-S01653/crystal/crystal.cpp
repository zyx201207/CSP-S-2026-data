#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010],c[500010];
int main()
{
	//please give me AC
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m,ans=0,tou=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++)
	{
		c[i]=a[i+1]-a[i];
		if(c[i]!=c[i-1]) tou=0;
	}
	if(tou)
	{
		cout<<m/(a[2]-a[1])+1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		ll sum=0,cnt=1;
		for(int j=i+1;j<=n;j++)
		{
			sum+=cnt*(a[j]-a[j-1]);
			cnt++;
			if(abs(sum)>m)
			{
				cnt--;
				break;
			}
		}
		cout<<sum<<" "<<cnt<<'\n';
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
