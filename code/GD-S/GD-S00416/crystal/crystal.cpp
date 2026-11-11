#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const ll M=5e5+5;
ll n,m,a[M],ans; 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	ll l=1,r=0,cnt=0;
	while(r+1<=n)
	{
		cnt+=(a[r+1]-a[r])*(r-l+1);
		r++;
		while(cnt>m&&l<=r) cnt-=(a[r]-a[l]),l++;
		if(cnt<=m) ans=max(ans,r-l+1);
	} 
	cout<<ans;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
