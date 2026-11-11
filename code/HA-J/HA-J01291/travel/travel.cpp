#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;bool b,b1,b2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2){
		cout << '1';
		b = 1;}
	else cout << '0';
	if (s1[0] == s2[0] && s1[1] == s2[1] && b){
		cout << '1';
		b1 = 1;}
	else cout << '0';
	if ((s1[2] <= 'C' && s2[2] <= 'C' || s1[2] >= 'D' && s2[2] >= 'D') && b1){
		cout << '1';
		b2 = 1;}
	else cout << '0';
	if (max(s1[2],s2[2]) - min(s1[2],s2[2]) == 1 && b2) cout << '1';
	else cout << '0';
	return 0;}
