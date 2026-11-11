#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	long long c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool q1 = c1 == c2;
	bool q2 = q1 && s1[0]==s2[0] && s1[1]==s2[1];
	bool _1 = s1[2]=='A' || s1[2]=='B' || s1[2]=='C';
	bool _2 = s2[2]=='A' || s2[2]=='B' || s2[2]=='C';
	bool q3 = q2 && (_1 == _2);
	bool q4 = q3 && (abs((long long)(s1[2]-s2[2]))==1 || (s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'));
	cout << q1 << q2 << q3 << q4;
	return 0;
} 
