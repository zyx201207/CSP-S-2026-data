#include<bits/stdc++.h>
using namespace std;

void solve(){
	int c1, c2;
	string s1, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000";
		return ;
	}
	else cout << '1';
	int d1 = stoi(s1), d2 = stoi(s2);
	if(d1 != d2){
		cout << "000";
		return ;
	}
	else cout << '1';
	char ch1 = s1[2], ch2 = s2[2];
	if(ch1 > ch2) swap(ch1, ch2);
	if((ch1 == 'D' && ch2 == 'F') || (ch1 >= 'A' && ch2 <= 'C')) cout << '1';
	else{
		cout << "00";
		return ;
	}
	if(ch1 != 'A' && ch2 != 'C') cout << '1';
	else cout << '0';
}

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T = 1;
	while(T--) solve();
	return 0;
}//pls±ð¿¨ÎÒ 
