#include<bits/stdc++.h>
#define ll long long
#define no ios::sync_with_stdio(0);
#define TLE cin.tie(0),cout.tie(0);
using namespace std;
const ll N=2e5+5;
ll n,a[N],ans=0;
char c[N];
void solve(){
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(ll i=1,j=n,now_i=0,now_j=0;i<=j;)
	{
		if(c[i]==c[j])
		{
			ll x=a[i]-now_i,y=a[j]-now_j;
			if(x>y)now_i+=y,now_j=0,j--;
			else if(x==y)now_i=now_j=0,i++,j--;
			else now_j+=x,now_i=0,i++;
		}
		else 
		{
			ll x=a[i]-now_i,y=a[j]-now_j;
			if(x>y)now_i+=y,now_j=0,j--,ans+=y;
			else if(x==y)now_i=now_j=0,i++,j--,ans+=x;
			else now_j+=x,now_i=0,i++,ans+=x;
		}
	}
	cout<<ans;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	no TLE
	ll _=1;
//	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}
