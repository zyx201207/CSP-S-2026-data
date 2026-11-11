#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int c22,s22;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> c2 >> s1 >> s2;
	if (c2[2]=='A') c22=1;
	else if (c2[2]=='B') c22=2;
	else if (c2[2]=='C') c22=3;
	else if (c2[2]=='D') c22=5;
	else if (c2[2]=='F') c22=6;
	
	if (s2[2]=='A') s22=1;
	else if (s2[2]=='B') s22=2;
	else if (s2[2]=='C') s22=3;
	else if (s2[2]=='D') s22=5;
	else if (s2[2]=='F') s22=6;
	if (c2==s2)
	{
		cout << "0000";
		return 0;
	}
	//ÅÐ¶ÏÒ»£º
	if (c1==s1) cout << "1";
	else cout << "0";
	//ÅÐ¶Ï¶þ£º
	if (c2[0]==s2[0] && c2[1]==s2[1]) cout << "1";
	else cout << "0";
	//ÅÐ¶ÏÈý£º
	if (c2[0]==s2[0] && c2[1]==s2[1] && ((c22<4 && s22<4) || (c22>4 && s22>4))) cout << "1";
	else cout << "0";
	//ÅÐ¶ÏËÄ£º
	if (c2[0]==s2[0] && c2[1]==s2[1] && abs(c22-s22)==1) cout << "1";
	else cout << "0";
	return 0;
}
