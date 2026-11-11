#include<bits/stdc++.h>
using namespace std;

string s;
long long a, ans;
char c;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    long long n;
    cin >> n;
    for(long long i = 1; i <= n; i++){
		cin >> a >> c;
		for(long long j = 1; j <= a; j++){
			s += c;
		}
	}
	long long l = s.size();
	for(long long i = 0; i < l / 2; i++){
		long long x = i + 1;
		if(s[i] != s[s.size() - x]){
			ans++;
		}
	}
	cout << ans;
    
    return 0;
}
