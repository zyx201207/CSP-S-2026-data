#include <bits/stdc++.h>
using namespace std;
char c1[5], s1[5], c2[5], s2[5];
char ans[10];
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1[0] == c2[0] && c1[1] == c2[1]){
		ans[0] = '1';
		if(s1[0] == s2[0] && s2[1] == s1[1]){
			ans[1] = '1';
			if(((s1[2] >= 'A' && s1[2] <= 'C') && (s1[2] >= 'A' && s1[2] <= 'C')) || ((s1[2] >= 'D' && s1[2] <= 'E') && (s1[2] >= 'D' && s1[2] <= 'E'))){
				ans[2] = '1';
				int a = s1[2] - 'A';
				int b = s2[2] - 'A';
				if((a >= 0 && b >= 0) && (a - 1 == b || a + 1 == b)){
					ans[3] = '1';
				} else ans[3] = '0';
			} else {
				ans[3] = '0';
				ans[2] = '0';
			}
		} else {
			ans[3] = '0';
			ans[2] = '0';
			ans[1] = '0';
		}
	} else {
		ans[3] = '0';
		ans[2] = '0';
		ans[1] = '0';
		ans[0] = '0';
	}
	for(int i = 0; i <= 3; i++){
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
