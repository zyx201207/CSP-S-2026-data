#include<bits/stdc++.h>

using namespace std;

bool b[5][5];

bool check(char c){
	if(c == 'A' || c == 'B' || c == 'C'){
		return false;//左侧
	}
	return true;//右侧
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	b[0][1] = 1;//a,b
	b[1][0] = 1;//b,a
	b[1][2] = 1;//b,c
	b[2][1] = 1;//c,b
	
	b[3][4] = 1;//d,f
	b[4][3] = 1;//f,d
	
	if(c1 == c2){
		cout << "1";
		if(s1[0] == s2[0] && s1[1] == s2[1]){
			cout << "1";
			if(check(s1[2]) == check(s2[2])){
				cout << "1";
				if(b[s1[2] - 'A'][s2[2] - 'A']){
					cout << "1";
				} else {
					cout << "0";
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}
