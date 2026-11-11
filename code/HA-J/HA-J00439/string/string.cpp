#include<iostream>
#include<string>
using namespace std;
int n;
string s;
long long l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	s = s + ' ';
	for(int i = 1;i <= n;i++){
		int c;
		char v;
		cin >> c >> v;
		for(int j = 1;j <= c;j++){
			s += v;
		}
		l += c;
	}
	//cout << s;
	int ans = 0;
	for(int i = 1;i <= l / 2;i++){
		if(s[i] != s[l - i + 1]) ans++;
	}
	cout << ans;
	return 0;
}
