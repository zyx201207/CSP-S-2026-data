#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll b[600000];
ll a[1000000];
queue<ll> s,s1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll m,n;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		s.push(a[i]);
	}
	for(ll i=1;i<=n;i++){
		s1=s;
		ll t=n-i+1;
		ll cnt1=i;
		while(t--){
			ll cnt=1;
			while(cnt<=n&&s1.front()!=a[cnt1]){
				s1.push(s1.front());
				s1.pop();
				cnt++;
			}
			if(s1.front()==a[cnt]){
				ll sl=n-cnt+1;
				while(sl--){
					s1.pop();
				}
			}else{
				s1.push(a[cnt]);
			}
			cnt1++;
		}
		while(!s1.empty()){
			b[s1.front()]++;
			s1.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
