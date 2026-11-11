#include<iostream>
#define ll long long
using namespace std;
ll a[1145141];
ll n,m;
ll check(ll x){
	ll cnt=0;
	for(ll i=1;i<=n;i++)
		if((a[i]&x)==x) cnt++;
	if(cnt>=m) return 1;
	else return 0;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	ll ans=0;
	for(ll i=30;i>=0;i--)
	{
		int new_ans=(1<<i)+ans;
		if(check(new_ans)) ans=new_ans; 
	}
	cout<<ans<<endl;
}
