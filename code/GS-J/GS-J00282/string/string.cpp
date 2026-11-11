#include<bits/stdc++.h>
using namespace std;
int a[200010];
char c[200010];
char s[200010];
bool b = 0;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, tmp = 1;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
		for(int j = tmp;j < tmp + a[i];j++){
			s[j] = c[i];
		}
		tmp += a[i];
	}
	int j = 1;
	for(int i = tmp;i >= 1;i--){
		c[j] = s[i];
		j++;
	}
		cout << 0;
	return 0;
}
