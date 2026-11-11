#include<bits/stdc++.h>
using namespace std;
int f(string s){//³µÏáºÅ 
	return (s[0] - '0') * 10 + s[1] - '0';
}
bool cmp(char a,char b,char c,char d){
	return (a == c && b == d) || (a == d && b == c);
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 != c2){
		cout << "0000";
		return 0;
	}
	int a1 = f(s1),a2 = f(s2);
	if(a1 != a2){
		cout << "1000";
		return 0;
	}
	char p1 = s1[2],p2 = s2[2];
	if(cmp(p1,p2,'D','F') || cmp(p1,p2,'A','B') || cmp(p1,p2,'C','B')){
		cout << "1111";
	}else if(cmp(p1,p2,'A','C')) cout << "1110";
	else cout << "1100";
	return 0;
}
