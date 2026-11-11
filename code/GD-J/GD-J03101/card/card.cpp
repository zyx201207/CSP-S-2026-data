#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef int ll;
const int N=500050;
ll n,m;
ll a[N];
ll ans[N];
void solve(){
	cin >> n >> m;
	for(ll i=1;i<=n;i++)cin >> a[i];
	for(ll i=1;i<=n;i++){
		bool chk[N];
		stack<ll> st;
		for(ll j=i;j<=n;j++){
			if(chk[a[j]])while(!st.empty()&&st.top()!=a[j])st.pop();
			st.push(a[j]);
			chk[a[j]]=1;
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(ll i=1;i<=m;i++)cout << ans[i] << ' ';
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	solve();
	return 0;
}
