#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool check(){
	char x = s2[2];
	char y = s4[2];
	if(x>y){
		swap(x,y);
	}
	if((x=='A' && y=='B') || (x=='A' && y=='C') || (x=='B' && y=='C') || (x=='D' && y=='F')){
		return true;
	}
	return false;
}
bool check1(){
	char x = s2[2];
	char y = s4[2];
	if(x>y){
		swap(x,y);
	}
	if((x=='A' && y=='B') || (x=='B' && y=='C') || (x=='D' && y=='F')){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> s1 >> s2 >> s3 >> s4;
	if(s1==s3){
		cout << 1;
		if(s2[0]==s4[0] && s2[1]==s4[1]){
			cout << 1;
			if(check()){
				cout << 1;
				if(check1()){
					cout << 1;
				}else{
					cout << 0;
				}
			}else{
				cout <<"00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	return 0;
} 
