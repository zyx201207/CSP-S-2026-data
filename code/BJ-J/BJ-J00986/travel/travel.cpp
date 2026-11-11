#include <bits/stdc++.h>
using namespace std;
bool yes(char a,char b){
	if((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F'))return 1;
	return 0;
}
bool yes2(char a,char b){
	if((a=='A'&&b=='B')||(a=='A'&&b=='C')||(a=='B'&&b=='C')||(a=='D'&&b=='F'))return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string c1,c2,s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	string s="",ss="";
	s+=s1[0];
	s+=s1[1];
	ss+=s2[0];
	ss+=s2[1];
	bool a=(c1==c2),b=(s==ss),c=(yes2(s1[2],s2[2])||yes2(s2[2],s1[2])),d=(yes(s1[2],s2[2])||yes(s2[2],s1[2]));
	if(a)cout << 1;
	else cout << 0;
	if(a&&b)cout << 1;
	else cout << 0;
	if(a&&b&&c)cout << 1;
	else cout << 0;
	if(a&&b&&c&&d)cout << 1;
	else cout << 0;
	return 0;
}