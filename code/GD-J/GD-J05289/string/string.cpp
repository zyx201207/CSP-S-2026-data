#include<bits/stdc++.h>
using namespace std;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	long long L = 0;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++){
		long long num;
		char c;
		cin >> num >> c;
		L += num;
		while(num --){
			s += c;
		}
	}
	long long ans = 0;
	L -= L % 2;
	for(long long i = 0; i <= L / 2 - 1; i ++){
		//cout << i << " " << L-i << endl;
		if(s[i] != s[L - i]){
		    ans ++;
		}
	}
	cout << ans;
	return 0;
}
