#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, cnt;
string s;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin>>n;
	for(int i = 1; i<=n; i++){
		ll x;
		char c;
		cin>>x>>c;
		for(int j = 1; j<=x; j++){
			s += c;
		}
	}
	
	for(int i = 0; 2*i<=s.size()-1; i++){
		if(s[i] != s[s.size()-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
	
	return 0;
}
