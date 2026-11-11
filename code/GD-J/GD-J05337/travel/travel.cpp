#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2; //same
	//1
	if(c1 == c2) cout << 1;
	else cout << 0;
	//2
	if(c1 == c2 &&
	   s1[0] == s2[0] && s1[1] == s2[1])
	   cout << 1;
	   else cout << 0;
	//3
	int t1, t2;
	if(s1[2] == 'A' || s1[2] == 'B' ||s1[2] == 'C')
		t1 = 1;
	else
		t1 = 2;
	if(s2[2] == 'A' || s2[2] == 'B' ||s2[2] == 'C')
		t2 = 1;
	else
		t2 = 2;
	bool t = 0;
	if(t1 == t2)
		t = 1;
	bool tt = 0;
	if(c1 == c2 &&
	   s1[0] == s2[0] && s1[1] == s2[1] &&
	   t)
	   {
	   		cout << 1;
	   		tt = 1;
	   }
	   else cout << 0;
	//4
	bool ttt = 0;
	if(s1[2] == 'A' && s2[2] == 'B' || s2[2] == 'A' && s1[2] == 'B' ||
	   s1[2] == 'B' && s2[2] == 'C' || s2[2] == 'B' && s1[2] == 'C' ||
	   s1[2] == 'D' && s2[2] == 'F' || s2[2] == 'D' && s1[2] == 'F')
		ttt = 1;
	if(tt && ttt)
		cout << 1;
	else cout << 0;
	return 0;
}
