#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
ll n,m,a[maxn],ans[maxn],ret;
char c[maxn];
void add(ll x){
	for(ll i=1;i<=40;i++){
		ll w=1ll<<(i-1);
		if(x&w){
			ans[i]++;
		}
	}
}
void del(ll x){
	for(ll i=1;i<=40;i++){
		ll w=1ll<<(i-1);
		if(x&w){
			ans[i]--;
		}
	}
}
ll sum(){
	ll cnt=0;
	for(int i=40;i>=1;i--){
		cnt*=2;
		if(ans[i]==m){
			cnt++;
		}
	}
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<m;i++){
		add(a[i]);
	}
	for(int i=1;i+m-1<=n;i++){
		ll r=i+m-1;
		add(a[r]);
		ret=max(ret,sum());
	//	cout<<sum()<<' '<<i<<' '<<r<<' '<<'\n';
	//	for(int j=1;j<=7;j++)cout<<ans[j]<<' ';
	//	cout<<'\n';
		del(a[i]);
	}
	cout<<ret;
	return 0;
}
