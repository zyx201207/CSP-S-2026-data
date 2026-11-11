#include <iostream> 
#include <string>
using namespace std;
long long a, n, ans = 0;
char c;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a >> c;
		for (int j = 1; j <= a; j++)
			s += c;
	}
	for (int i = 0; i < s.size() / 2; i++){
		if (s[i] == s[s.size() - i - 1]){
			continue;
		}
		ans++;
	}
	
	cout << ans;
	return 0;
}
