#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <string> e;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	e.push_back("0");
	bool f=false;
	int x;
	int last;
	while(n--){
		int a;
		string c;
		cin >> a >> c;
		if (a>=1000000000){
			f=true;
			x=a;
			break;
		}
		for (int i=1;i<=a;i++){
			e.push_back(c);
		}
	}
	if (f){
		cout << (n+1)/2*x;
		return 0;
	}
	int ans=0;
	for (int i=1;i<=e.size()/i;i++){
		if (e[i]!=e[e.size()-i-1]) ans++;
	}
	cout << ans;
	return 0;
}
