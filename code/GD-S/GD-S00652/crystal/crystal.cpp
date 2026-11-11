#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+10;
ll a[N];
ll n,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n); 
	ll w=1,res=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		while(w<i&&res>m) res-=a[i]-a[w],w++;
		ans=max(ans,i-w+1);
		if(i<n) res+=(i-w+1)*(a[i+1]-a[i]);
	}
	cout<<ans;
	return 0;
}
/*
20min
*/
