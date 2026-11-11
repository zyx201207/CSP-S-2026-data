#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, S[200005], RS[200005];
	long long ans = 0;
	char s[200005], Rs[200005];
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> S[i] >> s[i];
		RS[n - i - 1] = S[i];
		Rs[n - i - 1] = s[i]; 
	}
	long long o = 0, R = 0;
	while(o < n && R < n){
		if(RS[R] >= S[o]){
			ans += Rs[R]!=s[o]?S[o]:0;
			RS[R] -= S[o];
			o++;
		}
		else{
			ans += Rs[R]!=s[o]?RS[R]:0;
			S[o] -= RS[R];
			R++;
		}
	}
	cout << ans / 2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
