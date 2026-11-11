#include<bits/stdc++.h> 
using namespace std;
void f(char x,char y){
	if(x=='A'&&y=='B')cout << "1111";
	else if(x=='B'&&y=='A')cout << "1111";
	else if(x=='B'&&y=='C')cout << "1111"; 
	else if(x=='F'&&y=='D')cout << "1111";
	else if(x=='D'&&y=='F')cout << "1111";
	else cout << "1110";
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.ans","w",stdout);
	string s1,s2,s3,s4;
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1!=s3) cout << "0000";
	else {
		if(s2[0]!=s4[0]||s2[1]!=s4[1]) cout << "1000";
		else {
			if(s2[2]=='C'||s2[2]=='B'||s2[2]=='A'){
				if(s4[2]=='F'||s4[2]=='D') cout << "1100";
				else {
					f(s2[2],s4[2]);
				}
			}
			if(s2[2]=='F'||s2[2]=='D'){
				if(s4[2]=='C'||s4[2]=='B'||s4[2]=='A') cout << "1100";
				else {
					f(s2[2],s4[2]);
				}
			}
		} 
	}
	return 0;
}
/*
? 两张车票对应的座位是否在同一节车厢；
? 两张车票对应的座位是否在同一节车厢的同一排；
? 两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
? 两张车票对应的座位是否相邻。
100分 
*/
