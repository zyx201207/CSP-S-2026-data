#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define cin fin
#define cout fout
ifstream fin("string.in");
ofstream fout("string.out");
int main(){
	ll n;
	cin >> n;
	vector<pair<ll,char>> a(n+1);
	for(ll i = 1;i <= n;i++){
		ll num1;
		char num2;
		cin >> num1 >> num2;
		a[i].first = num1;
		a[i].second = num2;
	}
	if(n==1){
		cout << 0;
		return 0;
	}
	if(n <= 2){
		if(a[1].second == a[2].second){
			cout << 0;
			return 0;
		}
		cout << min(a[1].first,a[2].first);
		return 0;
	}
	
	string s="";
	for(ll i = 1;i <= n;i++){
		ll ni = a[i].first;
		char x = a[i].second;
		string si="";
		while(ni--){
			si+=x;
		}
		s+=si;
	}
	string x = s;
	reverse(s.begin(),s.end());
	ll num = (ll)s.size()/2,ans = 0;
	for(ll i = 0;i <= num;i++ ){
		if(x[i]!=s[i])ans++;
	}
	cout << ans;
	return 0;
	
}
