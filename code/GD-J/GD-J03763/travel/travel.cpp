#include <bits/stdc++.h>
using namespace std;
char c1[2], s1[3], c2[2], s2[3];

int main(){
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	for (int i = 0; i < 2; i++){
		cin >> c1[i];
	}
	for (int i = 0; i < 3; i++){
		cin >> s1[i];
	}
	for (int i = 0; i < 2; i++){
		cin >> c2[i];
	}
	for (int i = 0; i < 3; i++){
		cin >> s2[i];
	}

	bool ans[4] = {1, 1, 1, 1};
	for (int i = 0; i < 2; i++){
		if (c1[i] != c2[i]){
			ans[0] = 0;
			ans[1] = 0;
			ans[2] = 0;
			ans[3] = 0;
			for (int j = 0; j < 4; j++)
				cout << ans[j]; 
			return 0;
		}
	}
	for (int i = 0; i < 2; i++){
		if (s1[i] != s2[i]){
			ans[1] = 0;
			ans[2] = 0;
			ans[3] = 0;
			for (int j = 0; j < 4; j++)
				cout << ans[j];
			return 0;
		}
	}
	if (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C'){
		if (s2[2] == 'D' || s2[2] == 'E'){
			ans[2] = 0;
			ans[3] = 0;
			for (int j = 0; j < 4; j++)
				cout << ans[j];
			return 0;
		}
	}
	else{
		if (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C'){
			ans[2] = 0;
			ans[3] = 0;
			for (int j = 0; j < 4; j++)
				cout << ans[j];
			return 0;
		}
	}
	if (s1[2] - s2[2] != 1 && s2[2] - s1[2] != 1){
		ans[3] = 0;
		for (int j = 0; j < 4; j++)
				cout << ans[j];
		return 0;
	}
	
	for (int j = 0; j < 4; j++)
		cout << ans[j] << " ";
	return 0;
}
