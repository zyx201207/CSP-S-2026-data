#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,res;
string s;

void solve2000(){
	while(n--){
		ll x;char y;
		cin>>x>>y;
		while(x--) s=s+y;
	}
	
	for(ll i=0;i<s.size()/2;i++){
		char x=s[i],y=s[s.size()-i-1];
		cout<<x<<' '<<y<<'\n';
		if(x!=y) res++;
	}
	
	cout<<res;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(nullptr);

	cin>>n;
	
	if(n<=2000){
		solve2000();
		return 0; 
	}

	return 0;
}
