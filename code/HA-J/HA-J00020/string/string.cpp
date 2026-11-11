#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
vector<ll> a;
vector<char> c;
ll z1;
char z2;
vector<ll> s;
vector<int> to;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s.push_back(0);
	a.push_back(0);
	c.push_back('a');
	to.push_back(0);
	for(int i = 1;i <= n;i++){
		cin>>z1>>z2;
		a.push_back(z1);
		c.push_back(z2);
		s.push_back(s.back()+z1);
	}
	ll ans = 0;
    ll tot = s.back();
    ll lei = 0;
    for(ll i = 1;i <= tot/2;i++){
    	ll posl = lower_bound(s.begin(),s.end(),i)-s.begin();
    	ll posr = lower_bound(s.begin(),s.end(),tot-i+1)-s.begin();
    	ll tiao = min(s[posl]+1,tot-s[posr-1]+1);
    	if(tiao-1 <= tot/2){
    		if(c[posl] != c[posr]) ans += tiao-i;
    		i = tiao-1;
    	}
    	lei++;
    	if(lei >= 300005) break;
    	if(i >= tot/2) break;
    }
	cout<<ans;
	return 0;
}
