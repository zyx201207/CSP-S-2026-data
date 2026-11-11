#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2, a, b;
char c, d, nxt[3000];
bool f = 0;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2; 
	printf(c1 == c2 ? "1" : "0");
	if(c1 != c2) f = 1;
	a = b = "";
	for(int i = 0; i < (int)s1.size(); i++) if(isdigit(s1[i])) a += s1[i];
	for(int i = 0; i < (int)s2.size(); i++) if(isdigit(s2[i])) b += s2[i];
	printf(!f && a == b ? "1" : "0");
	if(a != b) f = 1;
	for(int i = 0; i < (int)s1.size(); i++) if(!isdigit(s1[i])) c = s1[i];
	for(int i = 0; i < (int)s2.size(); i++) if(!isdigit(s2[i])) d = s2[i];
	bool f1 = (c >= 'A' && c <= 'C'), f2 = (d >= 'A' && d <= 'C');
	printf(!f && f1 == f2 ? "1" : "0");
	if(f1 != f2) f = 1;
	nxt[(int)'A'] = 'B', nxt[(int)'B'] = 'C', nxt[(int)'D'] = 'F';
	bool f3 = (nxt[(int)c] == d || nxt[(int)d] == c);
	printf(!f && f3 ? "1" : "0");
	return 0;
}
