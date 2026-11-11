#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
long long b[200005];
long long ans = 0;
int p = 0;
string s;
int main(){
	freopen("string.in" , "r" , stdin);
	freopen("string.out" , "w" , stdout);
	cin >> n;
	if(n == 1){
		cout << 0;
		return 0;
	}
	for(int i = 1;i <= n;i ++){
		scanf("%lld" , &a[i]);
		cin >> c[i];
		for(int j = 1;j <= a[i];j ++){
			s += c[i];
		}
	}
	s += '\0';
	for(int i = s.size() / 2 + (s.size() % 2 != 0);i < s.size();i ++){
		if(s[i] != s[s.size() - i + 1]){
			ans ++;
			//cout << s[i] << " " << s[s.size() - i + 1] << "\n";
		} 
	}
	cout <<(ans - 1);
	return 0;
}
