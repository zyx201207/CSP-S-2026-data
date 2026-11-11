#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAXN=2*1e5+10;;
ll n,m,a[MAXN],ans[MAXN];
bool f[MAXN];
stack<ll> s;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		for(ll k=1;k<=m;k++){
			f[k]=false;
		}
		while(!s.empty()) s.pop();
		for(ll j=i;j<=n;j++){
			if(f[a[j]]){
				while(s.top()!=a[j]){
					f[s.top()]=false;
					s.pop();
				}
			}else{
				s.push(a[j]);
				f[a[j]]=true;
			}
		}
		for(ll k=1;k<=m;k++){
			if(f[k]){
				ans[k]++;
			}
		}
	}
	for(ll k=1;k<=m;k++){
		cout<<ans[k]<<' ';
	}
	return 0;
}
