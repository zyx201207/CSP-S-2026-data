#include <bits/stdc++.h>
using namespace std;

bool side(string x, string y){
	if(65 <= x[2] && x[2] <= 67 && 65 <= y[2] && y[2] <= 67){
		return true;
	}
	else if(68 <= x[2] && x[2] <= 70 && 68 <= y[2] && y[2] <= 70){
		return true;
	}
	else return false;
}

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, c2, s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	int ans[10];
	if(c1 == c2) ans[0] = 1;
	else ans[0] = 0;
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]) ans[1] = 1;
	else ans[1] = 0;
	if(ans[1] == 1 && side(s1, s2)) ans[2] = 1;
	else ans[2] = 0;
	if(ans[2] == 1){
		if(s1[2] >= 68) ans[3] = 1;
		else if(abs(s1[2] - s2[2]) == 1) ans[3] = 1;
		else ans[3] = 0;
	}
	else ans[3] = 0;
	
	for(int i = 0; i < 4; i ++) cout << ans[i];
	return 0;
} 
