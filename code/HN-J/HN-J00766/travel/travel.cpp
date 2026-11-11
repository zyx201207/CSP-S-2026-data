#include <bits/stdc++.h>

using namespace std;

string s1, s2, s3, s4;
bool f = 1;

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	for(int i = 0; i < 2; i++){
		if(s1[i] != s3[i])f = 0;
	}
	cout << f;
	for(int i = 0; i < 2; i++){
		if(s2[i] != s4[i])f = 0;
	}
	cout << f;
	if(!(s2[2] <= 'C' && s4[2] <= 'C') && !(s2[2] > 'C' && s4[2] > 'C')){
		f = 0;
	}
	cout << f;
	if(s2[2] + 1 != s4[2] && s2[2] != s4[2] + 1)f = 0;
	cout << f;
	return 0;
}
