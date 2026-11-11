#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2000005;
bool pd(string s){
	string m=s;
	reverse(m.begin(),m.end());
	if(m==s)return true;
	else return false;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll cnt=0;
	ll n;
	cin >> n;
	string s="";
	for(ll i=0;i<n;i++){
		int x;
		char op;
		cin >> x;
		cin >> op;
		for(int i=0;i<x;i++)s+=op;
	}
	if(pd(s)){
		cout << 0;
		return 0;
	}
	reverse(s.begin(),s.end());
	int bn=0;
	while(cnt<(int)s.size()){
		s[bn]=s[s.size()-1];
		bn++;
		cnt++;
		// cout << s << '\n';
		if(pd(s))break;
	}
	cout << cnt;
	return 0;
}































