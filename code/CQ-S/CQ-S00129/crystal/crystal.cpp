#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl '\n'
const int N=5e5+5;
ll n,m;
ll a[N],ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ll k=0;
	bool l=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2) k=a[2]-a[1];
		else if(i>=2 && (a[i]-a[i-1])!=k) l=0;
	}
	if(l){
		int idx=1;
		while(m>0){
			m-=(idx*k);
			if(m>=0) ans++;
			idx++;
		}
		cout<<ans+1;
		return 0;
	}
	sort(a+1,a+1+n);
	ll cnt=0,sum=m;
	int i=1;
	while(i<=n){
		cnt=0;
		sum=m;
		int idx=i-1;
		while(sum>0 && idx>=1){
			sum-=(a[i]-a[idx]);
			idx--;
			if(sum>=0) cnt++;
		}
		ll x=a[i];
		while(i<=n && a[i]==x){
			i++;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
    return 0;
}
