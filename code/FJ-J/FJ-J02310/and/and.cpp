#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a1[200005]={0},a2[200005]={0};
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m,a;
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a;
		queue<ll> s;
		while(a>0){
			s.push(a%2);
			a/=2;
		}
		while(!s.empty()){
			ll j=0;
			a2[j]=s.top();
			s.pop();
			j++;
		}
	}
	return 0;
}
