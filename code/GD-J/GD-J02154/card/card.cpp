#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e5 + 5;
ll n,m;
ll a[N];
ll b[N];
ll ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(ll i = 1;i <= n;i++){
		cin >> a[i];
	}
	stack<ll>st;
	for(ll i = 1;i <= n;i++){
		for(ll j = i;j <= n;j++){
			st.push(a[j]);
			b[a[j]]++;
			if(b[a[j]] == 2){
				ll s = st.top();
				b[s]--;
				st.pop();
				
				while(st.top() == a[j]){
					ll x = st.top();
					b[x]--;
					st.pop();
				}
			}
		}
		for(ll j = 1;j <= m;j++){
			if(b[i] > 0)ans[j]++;
			cout << b[i] << ' ';
		}
		cout << '|';
	}
	cout << '\n';
	for(ll i = 1;i <= m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
} 

