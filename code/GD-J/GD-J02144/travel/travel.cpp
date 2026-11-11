#include <bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
int get(string x){
	int ans=(x[0]-'0')*10+(x[1]-'0');
	return ans;
}
int in_left(char x){
	if(x=='D'||x=='F') return 1;
	return 0;
}
bool neibour(char x,char y){
	if(x>y) swap(x,y);
	if(x=='A'&&y=='B') return 1;
	if(x=='B'&&y=='C') return 1;
	if(x=='D'&&y=='F') return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a1 >> b1 >> a2 >> b2;
	int res=0;
	if(a1==a2){
		if(get(b1)==get(b2)){
			if(in_left(b1[2])==in_left(b2[2])){
				if(neibour(b1[2],b2[2])) cout << 1111;
				else cout << 1110;
			}else cout << 1100;
		}else cout << 1000;
	}else cout << "0000";
	return 0;
}
