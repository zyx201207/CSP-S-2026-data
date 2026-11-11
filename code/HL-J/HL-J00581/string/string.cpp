#include<bits/stdc++.h>
#define int long long
using namespace std; 
int n = 0, ans = 0, num = 0;
string s = "";
char ch = ' ';
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1 ; i <= n ; i++){
        cin >> num >> ch;
        while(num--){
        	s += ch;
		}
    }
    int len = (((int)s.length() / 2) % 2 ? (int)s.length() / 2 : (int)s.length() / 2 - 1);
    for(int i = 0 ; i <= len ; i++){
    	if(s[i] != s[(int)s.length() - i - 1]){
    		ans += 1;
		}
    }
    cout << ans << endl;
    return 0;
}

