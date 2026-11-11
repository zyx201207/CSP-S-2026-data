#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
bool fd(stack<ll> a,ll i){
	bool flag=0;
	while(a.size()){
		if(a.top()==i){
			flag=1;
			break;
		}
		a.pop();
	} 
	return flag;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	vector<ll>a(n+5),b(m+5);
	for(ll i=0;i<n;i++)cin>>a[i];
	for(ll i=0;i<n;i++){
		stack<ll>c;
		for(ll j=i;j<n;j++){
			if(fd(c,a[j])){
				ll k=c.top();
				while(c.size()!=0&&k!=a[j]){
					c.pop();
					k=c.top();
				}
				c.pop();
			}
			c.push(a[j]);
		}
		while(c.size()){
			ll s=c.top();c.pop();
			b[s]++;
		}
	}
	cout<<b[1];
	for(ll i=2;i<=m;i++)cout<<' '<<b[i]; 
	return 0;
}

