#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll n,m;
ll a[500010];
bool vis[300010];
ll ans[300010];
queue<ll> q1,q2;

void solve(){
	cin >> n >> m;
	for(ll i=1;i<=n;i++)cin >> a[i];
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++){
			ll x=a[j];
			if(vis[x]==0){
				q1.push(x);
				vis[x]=1;
			}
			else{
				for(ll k=1;k<=q1.size();k++){
					ll sz=q1.front();
					q1.pop();
					if(sz==x){
						while(q1.size()){
							ll szz=q1.front();
							q1.pop();
							vis[szz]=0;
						}
						break;
					}
					q2.push(sz);
				}
				while(q2.size()){
					ll sz=q2.front();
					q1.push(sz);
					q2.pop();
				}
				q1.push(x);
			}
		}
		while(q1.size()){
			ll sz=q1.front();
			ans[sz]++;
			vis[sz]=0;
			q1.pop();
		}
	}
	for(ll i=1;i<=m;i++)cout << ans[i]<<" ";
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	solve();
	return 0;
}
