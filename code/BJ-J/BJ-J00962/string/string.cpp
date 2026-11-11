#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
long long n, a[N], L;
char letter[N];
string S;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> letter[i];
		L += a[i];
		for(int t = 1; t <= a[i]; t++){
			S += letter[i];
		}
	}
	
	int times = 0;
	for(int i = 0; i <= L-1; i++){
		if(S[i] != S[L + 1 - i-2]){
			 S[L + 1 - i-2] = S[i];
			 times++;
		}
	}
	
	cout << times;
	return 0;
}
