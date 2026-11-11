#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct c{
	int ai;
	char ci;
};

bool isstr(string s){
	string t = s;
	reverse(t.begin(),t.end());
	if(s == t) return true;
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ll n,ans;
	cin >> n;
	vector<c> v(n + 1);
	for(int i = 0;i<n;i++) cin >> v[i].ai >> v[i].ci;
	if(n == 1) ans = 0;
	if(n == 2){
		if(v[0].ai == v[1].ai) ans = v[0].ai;
		else ans = min(v[0].ai,v[1].ai);
	}
	int len = 0;
	for(int i = 0;i<n;i++) len += v[i].ai;
	if(n > 2) ans = len / 2;
	cout << ans;
	return 0;
}
