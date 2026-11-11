#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, cnt;
struct N{
	int a;
	char c;
}s[200005];
signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> s[i].a >> s[i].c;
	}
	for (int i = 1, j = n; i <= j; ){
		if (s[i].c == s[j].c){
			if (s[i].a > s[j].a){
				s[i].a -= s[j].a;
				s[j].a = 0;
				j--;
			}
			else if (s[i].a < s[j].a){
				s[j].a -= s[i].a;
				s[i].a = 0;
				i++;
			}
			else if (s[i].a == s[j].a){
				s[i].a = 0;
				s[j].a = 0;
				i++;
				j--;
			}
		}
		else{
			if (s[i].a > s[j].a){
				cnt += s[j].a;
				s[i].a -= s[j].a;
				s[j].a = 0;
				j--;
			}
			else if (s[i].a < s[j].a){
				cnt += s[i].a;
				s[j].a -= s[i].a;
				s[i].a = 0;
				i++;
			}
			else if (s[i].a == s[j].a){
				cnt += s[i].a;
				s[i].a = 0;
				s[j].a = 0;
				i++;
				j--;
			}
		}
	}
	cout << cnt;
	return 0;
}
