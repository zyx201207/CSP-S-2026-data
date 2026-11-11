//GZ-J00395  贵阳市第三实验中学  闫张玴
#include <bits/stdc++.h> 
using namespace std;
string c, s, cc, ss;
string ans="";
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c >> s >> cc >> ss;
	if(c == cc) ans+="1";
	else {
		cout << "0000";
		return 0;
	}
	int q = (s[0]-'0')*10+s[1] - '0', qq = (ss[0]-'0')*10+ss[1] - '0';
	if(q == qq) ans+="1";
	else {
		cout << "1000";
		return 0;
	} 
	char w = s[2], ww = ss[2];
	int f=0, ff=0;
	if(w == 'A' || w == 'B' || w == 'C') f = 0;
	else f = 1;
	if(ww == 'A' || ww == 'B' || ww == 'C') ff = 0;
	else ff = 1;	
	if(f == ff) ans+="1";
	else {
		cout << "1100";
		return 0;
	}
	if(((char) (w+1) == ww || (char) (w-1) == ww) && (w != 'C' && ww != 'D' || w != 'D' && ww != 'C') ) ans+="1";
	else {
		cout << "1110";
		return 0;
	}
	cout << ans;
	return 0;
}
