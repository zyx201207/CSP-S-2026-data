#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

struct node{
	int len; char c;
};

int main() {
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ll n,a; char c;
	cin >> n;
	
	vector<int> va; vector<char> vc;
	vector<node> v;
	
	ll maxa = 0;
	for(int i = 1;i <= n;i++) {
		cin >> a >> c;
		maxa = max(maxa,a);
		va.push_back(a);
		vc.push_back(c);
	}

	if(n * maxa > 1e8) {
		for(int i = 0;i < n-1;i++) {
			if(vc[i] == vc[i+1]) {
				va[i+1] += va[i];
				va[i] = 0;
			}
		}
		for(int i = 0;i < n;i++) {
			if(va[i]) {
				v.push_back({va[i],vc[i]});
			}
		}
		
		int l = v.size();
		if(l == 1) {
			cout << 0;
			return 0;
		}
		if(l == 2) {
			int l1 = v[0].len,l2 = v[1].len;
			if(l1 == l2) cout << l1;
			else if(l1 > l2) cout << l1-l2;
			else cout << l2-l1;
			return 0;
		}
		
		ll cnt = 0;
		int i = 0,j = l-1;
		while(i < j) {
			int l1 = v[i].len,l2 = v[j].len;
			if(v[i].c == v[j].c) {
				v[i].len -= min(l1,l2);
				v[j].len -= min(l1,l2);
				if(v[i].len) j++;
				else i++;
			}
			else {
				if(l1==l2) {
					cnt += l1;
					i++; j++;
				}
				else {
					cnt += abs(l1-l2);
					v[i].len -= min(l1,l2);
					v[j].len -= min(l1,l2);
					if(v[i].len) i++;
					else j++;
				}
			}
		}
		
		cout << cnt;		
	}
	
	else {
		string s = "";
		for(int i = 1;i <= n;i++) {
			int a = va[i]; char c = vc[i];
			while(a--) s += c;
		}
		int l = s.size();
		cout << s << endl;
		
		ll cnt = 0;
		for(ll i = 0;i < l;i++) {
			ll j = l-i;
			if(i<j && s[i] != s[j]) cnt++;
		} 
		
		cout << cnt;
	}
	
	return 0;
}
