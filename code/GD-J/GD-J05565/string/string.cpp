#include <iostream>
using namespace std;
int n;
long long a[200005];
char s[200005];
char ss[2000005], pos;
long long ans;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> s[i];
		if(s[i] == s[i - 1]){
			a[i - 1] += a[i];
			i--;
			n--;
		}
	}
	if(n == 1){
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= a[i]; j++) ss[++pos] = s[i];
	}
	for(int i = 1; i <= pos / 2; i++){
		if(ss[i] != ss[pos - i + 1]) ans++;
	}
	cout << ans;
	return 0;
}
