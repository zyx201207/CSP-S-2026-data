#include<bits/stdc++.h>
using namespace std;
int a, b;
string s1, s2;
int main(){
	freopen("travel.in","r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> s1 >> b >> s2;
	if(a == b) cout << '1';
	else cout << '0';
	int r = (s1[0] - '0') * 10 + (s1[1] - '0');
	int x = (s2[0] - '0') * 10 + (s2[1] - '0');
	if(r == x && a == b) cout << '1';
	else cout << '0';
	if((r == x && a == b && s1[2] == 'D' && s2[2] == 'F') || (r == x && a == b && s1[2] == 'F' && s2[2] == 'D')) cout << '1';
	else if(r == x && a == b && s2[2] <= 'C' && s2[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A') cout << '1';
	else cout << '0';
	if((r == x && a == b && s1[2] == s2[2]+1 && s2[2] != 'C') || (r == x && a == b && s1[2] == s2[2]-1 && s1[2] != 'C')){
		cout << '1';
	}else{
		cout << '0';
	}
	return 0;
}
