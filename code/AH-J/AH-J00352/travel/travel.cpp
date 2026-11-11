#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a, b;
	string s1, s2;
	bool tongpai = 0, tongce = 0, tongche = 0;
	cin >> a >> s1 >> b >> s2;
	if(a == b){
		tongche = 1;
		cout << 1;
	}else cout << 0;
	if(tongche && s1[0] == s2[0] && s1[1] ==s2[1]){
		tongpai = 1;
		cout << 1;
	}else cout << 0;
	if(!tongche || !tongpai) cout << 0; 
	else if((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C')){
			tongce = 1;
			cout << 1;
	}else cout << 0;
	if(tongche && tongpai && tongce && abs(s1[2] - s2[2]) == 1) cout << 1;
	else cout << 0;
	return 0;
}
