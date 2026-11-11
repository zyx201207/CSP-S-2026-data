#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const int maxn =5e5+10;
ll a[maxn],m;
int ans=1;
ll s[maxn];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		if(i==1) continue;
		else s[i-1]=(a[i]-a[i-1])+s[i-2];
	}
	ll cnt=0; int l=1,r=1;
	for(int i=2;i<=n;i++)
	{
		cnt+=(a[i]-a[i-1])*(r-l+1);
		r=i;
		if(cnt<=m)
		{
			ans=max(ans,r-l+1);
		}
		else{
			while(l<r&&cnt>m)
			{
				cnt-=(s[r-1]-s[l-1]);
				l++;
			}
			ans=max(ans,r-l+1);
		}
	}
	cout<<ans;
	return 0;
 } 
