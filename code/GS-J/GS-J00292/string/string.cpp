#include<bits/stdc++.h>
using namespace std;

long long n,a,ans = 0,len;
char c;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a >> c;
		for(int j = 1;j <= a;j++){
			s += c;
		}
	}
	len = s.length();
	//cout << s.length() << "\n";
	//cout << s << "\n";
	for(int i = 0;i < s.length() / 2 + s.length() % 2;i++){
		if(s[i] != s[len - i - 1]){
			//cout << i << " " << len - i - 1 << '\n';
			ans++;
			s[len - i - 1] = s[i];
		}else{
			continue;
		}
	}
	cout << ans;
	return 0;
}
