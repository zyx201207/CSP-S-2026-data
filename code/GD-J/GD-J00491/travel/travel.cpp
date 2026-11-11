#include<bits/stdc++.h>

using namespace std;

string s1, s2, c1, c2;
char x[5] = {'A', 'B', 'C', 'D', 'E'};
int ans[2];

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.cout", "w", stdout);
	
	getline(cin, c1);
	getline(cin, s1);
	getline(cin, c2);
	getline(cin, s2);
	if (c1 == c2){
		cout << "1";
		if (s1[2] == s2[2] && s1[3] == s2[3]){
			cout << "1";
			if ((s1[1] == 'C' || s1[1] == 'B' || s1[1] == 'A') && (s2[1] == 'C' || s2[1] == 'B' || s2[1] == 'A') ){
				cout << "1";
				for (int i = 1; i <= 3; i ++){
					if (s1[1] == x[i]) ans[1] = i;
					if (s2[1] == x[i]) ans[2] = i;
				}
				if (abs(ans[1] - ans[2]) == 1) cout << "1";
				else cout << "0";
			}
			else if ((s1[1] == 's2' || s1[1] == 's1') && (s2[1] == 's2' || s2[1] == 's1')) cout << "11";
			else cout << "00";
		}
		else if (s1[2] != s2[2] && s1[3] != s2[3]) cout << "000";
	}
	else cout << "0000";

    return 0;
}
