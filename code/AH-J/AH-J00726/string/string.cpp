#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    ll n,cnt=0;
    cin>>n;
	for(ll i=1;i<=n;i++){
		int ai;
		char ci;
		cin>>ai>>ci;
		for(ll j=1;j<=ai;j++) s+=ci;
	}
	int z=0,y=s.size()-1;
	while(z<=y){
		if(s[z]!=s[y]) cnt++;
		z++;
		y--;
	}
	cout<<cnt;
    return 0;
}
