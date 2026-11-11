#include<bits/stdc++.h>
using namespace std;
//#define JUDGE
#define int long long
int read(){
	int x = 0,f = 1;
	char ch = getchar();
	while(ch < '0'||ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9')x = (x << 3) + (x << 1) + (ch - '0'),ch = getchar();
	return x * f;
}
const int N = 1e6 + 10;
string c1,s1,c2,s2;
bool tag1,tag2,tag3,tag4;
void input(){
	cin >> c1 >> s1 >> c2 >> s2;
}
void solve(){
	input();
	if(c1 == c2)tag1 = 1;
	string l1 = s1.substr(0,2),l2 = s2.substr(0,2);
	if(l1 == l2)tag2 = 1;
	tag2 &= tag1;
	string p1 = s1.substr(2,3),p2 = s2.substr(2,3);
	int po1,po2;
	if(p1 == "A")po1 = 1;
	if(p1 == "B")po1 = 2;
	if(p1 == "C")po1 = 3;
	if(p1 == "D")po1 = 6;
	if(p1 == "F")po1 = 7;
	if(p2 == "A")po2 = 1;
	if(p2 == "B")po2 = 2;
	if(p2 == "C")po2 = 3;
	if(p2 == "D")po2 = 6;
	if(p2 == "F")po2 = 7;
	if(abs(po1 - po2) <= 2)tag3 = 1;
	tag3 &= tag2;
	if(abs(po1 - po2) == 1)tag4 = 1;
	tag4 &= tag3;
	cout << tag1 << tag2 << tag3 << tag4;
}
signed main( ){
#ifndef JUDGE
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
#endif
	int _ = 1;
	//cin >> _;
	while(_--)solve();
	return 0;
}
