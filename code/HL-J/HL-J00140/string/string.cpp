#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
    int n;
    cin >> n;
    string s = "";

    for (int i = 0; i < n; i++) {
    	long long a;
        char a_;
        cin >> a >> a_;
        long long len = s.size();
        
		for (long long j = len; j < len + a; j++) {
			s += a_;
		}
    }

	long long len = s.size();
    string k;
    for (long long i = len - 1; i >= 0; i--) {
         k[i] = s[n - 1 - i];
    }

    int flag = 0;
	long long cnt = 0;
    for (long long i = 0; i <= len; i++) {
        if (k[i] != s[i]) {
            flag = 1;
            cnt++;
        }
    }

    if (!flag) {
        cout << "0";
        return 0;
    }

    cout << (cnt - 1) / 2 + 1;
    
    
    fclose(stdin);
	fclose(stdout); 
    return 0;
}
