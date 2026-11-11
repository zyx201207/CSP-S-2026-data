#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    string s;
    long long L = 0;
    for (int i = 1;i <= n;i++){
    	int a;
    	char c;
    	cin >> a >> c;
    	L += a; 
    	for (int j = 1;j <= a;j++) s += c;
	}
	s = ' ' + s;
	
	long long ans = 0;
	for (int l = 1;l <= L;l++){
		int r = L+1-l;
		if (l >= r) break;
		if (s[l] != s[r]) ans++;
	}
	
	cout << ans << '\n';

    return 0;
}


