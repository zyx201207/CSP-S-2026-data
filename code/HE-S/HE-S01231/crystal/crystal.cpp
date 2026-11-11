#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m;
ll a[500005];
bool cmp(ll x,ll y){
	return x>y;
}
bool flag=1;
bool flag1=1;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flag=0;
	}
	ll cha=a[2]-a[1];
	for(int i=3;i<=n;i++) if(a[i]-a[i-1] != cha) flag1=0;
	if(flag){
		ll cnt=(1+n)*n/2-n;
		ll pre=n-1;
		ll cnt1=0;
		while(m<cnt){
			cnt-=pre;
			pre--;
			cnt1++;
		}
		cout<<n-1-cnt1+1;
		return 0; 
	}
	if(flag1){
		ll cnt=(cha+cha*(n-1))*(n-1)/2;
		ll pre=cha*(n-1);
		ll cnt1=0;
		while(m<cnt){
			cnt-=pre;
			pre-=cha;
			cnt1++;
		}
		cout<<n-1-cnt1+1;
		return 0; 
	}
	sort(a+1,a+n+1,cmp);
	ll maxx=-0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		ll cnt=1;
		ll k=m;
		for(int j=i+1;j<=n;j++){
			if(a[i]-a[j]<=k){
				k-=(a[i]-a[j]);
				cnt++;
			}
			else continue;
		}
		maxx=max(maxx,cnt);
	}
	cout<<maxx;
	return 0;
} 
