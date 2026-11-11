#include <bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;
bool ch1, ch2, ch3, ch4;
int x1, x2, y_1, y_2;
void init(){
	int len1=s1.length();
	for(int i=0;i<len1-1;i++){
		x1=x1*10+s1[i]-'0';
	}
	y_1=s1[len1-1]-'A'+1;
	if(y_1==4)y_1+=1;
	int len2=s2.length();
	for(int i=0;i<len2-1;i++){
		x2=x2*10+s2[i]-'0';
	}
	y_2=s2[len2-1]-'A'+1;
	if(y_2==4)y_2+=1;
//	cout << x1 << " " << y_1 << "\n";
//	cout << x2 << " " << y_2 << "\n";
	return ;
}
void out(bool x){
	if(x==true)cout << 1;
	else cout << 0;
	return ;
}
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c1 >> s1 >> c2 >> s2;
	init();
	if(c1==c2)ch1=true;
	if(ch1 && x1==x2)ch2=true;
	if(ch2 && ((y_1>4 && y_2>4) || (y_1<4 && y_2<4)))ch3=true;
	if(ch3 && abs(y_1-y_2)==1)ch4=true;
	out(ch1);out(ch2);out(ch3);out(ch4);
	return 0;
}
