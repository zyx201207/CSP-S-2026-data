#include <bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;
bool a, b, c, d;
bool cmp1(){
	return ((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'));
} 
bool cmp2() {
	if(s1[2]=='A'&&s2[2]=='B') return 1;
	if(s1[2]=='C'&&s2[2]=='B') return 1;
	if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')) return 1;
	if(s1[2]=='D'&&s2[2]=='F') return 1;
	if(s1[2]=='F'&&s2[2]=='D') return 1;
	return 0;
}
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1", a=1;
	else cout<<"0";
	if(a&&s1[0]==s2[0]&&s1[1]==s2[1]) cout<<"1", b=1;
	else cout<<"0";
	if(b&&cmp1()) cout<<"1", c=1;
	else cout<<"0";
	if(c&&cmp2()) cout<<"1"; 
	else cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
