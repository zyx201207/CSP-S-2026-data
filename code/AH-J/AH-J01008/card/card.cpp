#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[300005],vis[300005],a[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		queue<ll> q;
		memset(vis,0,sizeof vis);
		for(ll j=i;j<=n;j++){
			if(vis[a[j]]==0){
				q.push(a[j]);
				vis[a[j]]=1;
			}
			else{
				while(!q.empty()) q.pop();
				q.push(a[j]);
			}
		}
		while(!q.empty()){
			ll o=q.front();
			q.pop();
			cnt[o]++;
		}
	}
	for(ll i=1;i<=m;i++) cout<<cnt[i]<<"\n";
	
	return 0;
}
