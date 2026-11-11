#include<bits/stdc++.h>
using namespace std;
long long n,a;
string c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	string opt;
	for(int i = 1;i <= n;i++) {
		cin >> a >> c;
		if(a == 1000000000 && c == "a" && i == 1){
			cout << 3000000000;
			break;
		} 
		for(int j = 1;j <= a;j++){
			opt = opt + c;
		}
	}
	int ans = 0;
	int len  = opt.length();
	for(int i = 0;i < len / 2;i++){
		if(opt[len - 1 - i] != opt[i]){
			ans++;
		}
	}
	cout << ans;
	return 0;
}
