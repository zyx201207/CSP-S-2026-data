//∏ …≠É| GZ-J00367 
#include<bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
int cnt = 1;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) cout << 1;
	else cout << 0;
    if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]){
    	cout << 1;
	}
	else cout << 0;
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && s1[2] <= 'C' && s2[2] <= 'C'){
		cout << 1;
		cnt++;
	}
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && s1[2] > 'C' && s2[2] > 'C'){
		cout <<1; 
		cnt++;
	}
	if(cnt > 0) cout << 0; 
	
	if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && (int(s1[2]) + 1 == int(s2[2]) || int(s1[2]) - 1 == int(s2[2]))){
		if((s1[2] == 'C' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'C')) {
			cout <<0;
			return 0; 
		}
		cout << 1;
	}
	else cout <<0; 
	return 0;
}
