#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n,a[200005],ans=0,m;
ll s[200005][35];
bool f[35];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		ans=max(ans,a[i]);
		ll x=a[i],j=34;
		while(x!=0)
		{
			if(x%2==1) s[i][j--]=1;
			else j--;
			x/=2;
		}
	}
	if(m==1)
	{
		cout<<ans;
		return 0;
	}
	for(int i=34;i>=1;i--)
	{
	    ll cnt=0;
		for(int j=1;j<=n;j++)
		{
			
			if(s[j][i]==1) cnt++;
		}
		if(cnt>=m) f[i]=true;
	}
	ans=0;ll res=1;
	for(int i=34;i>=1;i--)
	{
		if(f[i]) ans+=res;
		res*=2;
	}
	cout<<ans; 
	return 0;
} 
