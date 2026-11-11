#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	char b1, b2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	
	b1=s1[2];
	b2=s2[2];
	
	int f1=0, f2=0, f3=0, f4=0;
	
	if(c1==c2) f1 = 1;
	if(f1){
		if(s1[0]==s2[0]&&s1[1]==s2[1]) f2 = 1;
	}
	if(f1&&f2){
		if((b1=='A'||b1=='B'||b1=='C')&&(b2=='A'||b2=='B'||b2=='C')) f3 = 1;
		if((b1=='D'||b1=='F')&&(b2=='D'||b2=='F')) f3 = 2;
	}
	if(f1&&f2&&f3){
		if(f3==1){
			if(int(b1)==int(b2)+1||int(b1)==int(b2)-1) f4 = 1;
		}
		if(f3==2){
			if(int(b1)==int(b2)+2||int(b1)==int(b2)-2) f4 = 1;
		}
	}
	cout << f1 << f2 << bool(f3)<< f4;
	
	return 0;
}
