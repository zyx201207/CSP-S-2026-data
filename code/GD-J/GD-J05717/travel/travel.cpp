#include<bits/stdc++.h>
using namespace std;
int c1, c2, row1, row2;
string s1, s2;
bool ans[4];
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	row1 = (s1[0]-'0')*10+s1[1]-'0';
	row2 = (s2[0]-'0')*10+s2[1]-'0';
	if(c1 == c2){
		ans[0] = 1;
		if(row1 == row2){
			ans[1] = 1;
			if(s1[2] >= 'D' && s2[2] >= 'D'){
				ans[2] = 1;
				ans[3] = 1;
			}
			if(s1[2] <= 'C' && s2[2] <= 'C'){
				ans[2] = 1;
				if(abs(s1[2]-s2[2]) == 1){
					ans[3] = 1;
				}
			}
		}
	}
	for(int i = 0; i < 4; i++){
		cout << ans[i];
	}
	return 0;
}
