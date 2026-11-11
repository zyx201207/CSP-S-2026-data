#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int _ = 1;//cin >> _;
	while(_--){
		int n;cin >> n;
		string s = "";
		for(int i=1;i<=n;i++){
			int a;char c;cin >> a >> c;
			for(int i=1;i<=a;i++)s += c;
		}
		int cnt = 0;
		int l = s.size();s = "#" + s;
		//cerr << s << "\n";
		for(int i=1;i<=l/2;i++)
			if(s[i] != s[l-i+1])cnt++;
		cout << cnt;
	}
	return 0;
}

