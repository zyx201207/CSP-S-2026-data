#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m,a[500010],ans[500010];
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	for(ll i=1;i<=n;i++){
		stack<ll> s;
		for(ll j=i;j<=n;j++){
			stack<ll> t=s;
			while(!t.empty()){
				if(t.top()==a[j]){
					t.pop();
					s=t;
					continue;
				}
				t.pop();
			}
			s.push(a[j]);
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(ll i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

