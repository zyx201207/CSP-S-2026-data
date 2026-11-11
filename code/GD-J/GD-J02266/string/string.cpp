#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long m = 0;
	cin >> n;
	string s;
	for(int i = 1; i <= n; i++){
		int x;
		char y;
		cin >> x >> y;
		m += x;
		for(int j = 1; j <= x; j++){
			s += y;
		}
	}
	string f;
	for(int i = 0; i < m/2; i++){
		f += s[i];
	}
	
	long long id1 = 0;
	long long ans = 0;
	for(int j = s.size()-1; j > m/2; j--){
		if(f[id1++] != s[j]){
			ans++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
