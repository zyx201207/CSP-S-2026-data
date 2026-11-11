#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 5e8;
ll n,ans;
char s[N];
int id = -1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll n1 = n;
	while(n--){
		ll a;
		char c;
		cin>>a>>c;
		while(a--) s[++id] = c;
	}
	for(ll i = 0;i < id/2;i++){
		if(s[i] != s[id-(i+1)]) ans++;
	}
	cout<<ans;
	return 0;
}
