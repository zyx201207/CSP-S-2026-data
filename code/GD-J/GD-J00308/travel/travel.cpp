#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1, s1, c2, s2;
bool check1(){return c1 == c2;}
bool check2(){return s1[0] == s2[0] && s1[1] == s2[1];}
bool check3(){return (s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] > 'C' && s2[2] > 'C');}
bool check4(){
	if(s2[2] > s1[2]) swap(s1, s2);
	if(s1[2] <= 'C' && s1[2] == (char)(s2[2] + 1)) return 1;
	if(s1[2] == 'F' && s2[2] == 'D') return 1;
	return 0;
}
signed main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(!check1()) cout << "0000\n";
	else if(!check2()) cout << "1000\n";
	else if(!check3()) cout << "1100\n";
	else if(check4()) cout << "1111\n";
	else cout << "1110\n";
	return 0;
}
