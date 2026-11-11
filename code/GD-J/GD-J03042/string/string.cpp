#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL cishu(string x){
	string y;
	for(LL i=x.size()-1; i>=0; i--){
		y+=x[i];
	}

	LL ans=0;
	for(LL i=0; i<=x.size(); i++){
		if(x[i]!=y[i]) ans++;
	}

	return ans/2;
}

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	string s;
	int n; cin >> n;
	for(int i=1; i<=n; i++){
		int a; char c; cin >> a >> c;
		for(int j=1; j<=a; j++){
			s+=c;
		}
	}

	cout << cishu(s);
	return 0;
}
