#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5;
ll a[N];
ll n,m;
ll mn=1,mx=-1;
ll cnt=0,x=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.ans","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		cnt++;
		x+=((a[i]-a[i-1])*(cnt-1));
		while(x>m){
			cnt--;
			x-=(a[i]-a[mn]);
			mn++;
		}
		mx=max(mx,cnt);
	}
	cout<<mx;
	return 0;
}
