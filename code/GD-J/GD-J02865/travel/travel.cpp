#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("trave.in", "r", stdin);
	freopen("trave.out", "w", stdout);
	
	int c1, c2;
	string s1, s2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	char a=s1[0], b=s1[1];
	char a1=s2[0], b1=s2[1];
	if(a!=a1||b!=b1){
		cout<<"1000";
		return 0;
	}
	char y1 = s1[2];
	char y2 = s2[2];
	if((y1=='A'&&y2=='B') || (y2=='A'&&y1=='B') || (y1=='C'&&y2=='B') || (y2=='C'&&y1=='B') || (y1=='D' && y2=='F')||(y1=='F' && y2=='D')){
		cout<<"1111";
	}
	else if(((y1=='D' || y1=='F')&&(y2!='F' || y2 !='D')) || ((y2=='D' || y2=='F')&&(y1!='F' || y1 !='D'))){
		cout<<"1100";
	}
	else cout<<"1110";
	
	return 0;
} 
