#include<bits/stdc++.h>
using namespace std;
int n, l = 1, ans;
char s[100000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		long long t;
		char tt;
		cin >> t >> tt;
		for(int j = l; j <= l+t; j++){
			s[j] = tt;
		}
		l+=t;
	}
	for (int i = 1; i <= l/2; i++) if(s[i]!=s[l+1-i]) ans++;
	cout << ans;
}
