//GZ-J00368 贵阳市第三十三中学 叶发睿 
#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int n;
int m;
char a;
int cnt = 0;
string s;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> m >> a; 
		for(int i = 1; i <= m; i++){
			s += a;
		}
		
	}
	string t = s;
	reverse(t.begin(), t.end());
	if(t == s){
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		if(t[i] != s[i]){
			t[i] = s[i];
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
