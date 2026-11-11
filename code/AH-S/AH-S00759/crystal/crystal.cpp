#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int a[N];
ll s[N];
ll n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+1ll*a[i];
	}
	int ans=0;
	int l=1;
	for(int r=1;r<=n;r++)
	{
		ll f=1ll*(r-l+1)*a[r]-(s[r]-s[l-1]);
		if(f<=m)
		{
			ans=(r-l+1)>ans?(r-l+1):ans;
		}
		else
		{
			while(f>m&&l<r)
			{
				l++;
				f=1ll*(r-l+1)*a[r]-(s[r]-s[l-1]);
			}
		}
	}
	cout<<ans;
	return 0;
} 
/*
5 5 
1 2 4 8 9

5 8 
-3 -1 2 2 7
*/
