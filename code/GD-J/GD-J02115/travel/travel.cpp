#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;	//c车厢号，s座位号 
	cin >> c1 >> s1 >> c2 >> s2;
	bool ans1 = (c1==c2);
	cout << ans1;
	
	//ans2有问题 
	char s1al = s1[2], s2al = s2[2], 
		 s10 = s1[0], s11 = s1[1], 
		 s20 = s2[0], s21 = s2[1];
	//string s1num = s1[0]+s1[1], s2num = s2[0]+s2[1];
	//int s1num = ((char)s1[0]-'0')*10+((char)s1[1]-'0'), s2num = ((char)s2[0]-'0')*10+((char)s2[1]-'0');
	int s1num = (s10-'0')*10+(s11-'0'), s2num = (s20-'0')*10+(s21-'0');
	//cout << s1num << ' ' << s1al << ' ' << s2num << ' ' << s2al << endl;
	bool ans2 = (ans1&&(s1num==s2num));
	cout << ans2;
	
	bool sd1 = (('A'<=s1al<='C') && ('A'<=s2al<='C')), sd2 = (('D'<=s1al<='E') && ('D'<=s2al<='E'));
	bool same_side = (sd1 || sd2);
	bool ans3 = (ans2&&same_side);
	cout << ans3;
	
	bool ans4 = (ans3&&(abs(s2al-s1al)==1));
	cout << ans4;
	return 0;
}
