#include <bits\stdc++.h>
using namespace std;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	string S;
	int n, l=0, ans=0;
	cin >> n;
	for(int i = 1; i<=n; i++){
		int a;
		string b;
		l+=a;
		cin >> a >> b;
		for(int j = 1; j<=a; j++){
			S+=b; 
		}
	}

	for(int i = 0; i<=l/2-1; i++){
		if(S[i] != S[l-i-1]){
			ans++;
		}
	}
	
	cout << ans;
	return 0;
}
