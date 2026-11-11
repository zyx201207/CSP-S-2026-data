//兰玉昊 GZ-J00057 观山湖中学Trick||Treat!
#include<bits/stdc++.h>
using namespace std;

int n, a, ans;
string s;
char c;

int main(){
	cin.tie(0) -> sync_with_stdio(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
            cin >> a >> c;
        for(int j = 1;j <= a;j++){
            s += c;
        }
	}
	for(int i = 0,j = s.size()-1;i < j;i++, j--){
        if(s[i] != s[j]) ans++;
	}
	cout << ans;
	return 0;
}
