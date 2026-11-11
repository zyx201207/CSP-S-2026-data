#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1;
	cin>>c2>>s2;
	int t=0;
	int num1=0,num2=0;
	char a=s1[2],b=s2[2];
	if(c1==c2){
		t+=1000;
		num1=s1[0]*10+s1[1];
		num2=s2[0]*10+s2[1];
		if(num1==num2){
			t+=100;
			if(((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C'))||((a=='D'||a=='F')&&(b=='D'||b=='F'))){
				t+=10;
				if((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F')||(b=='A'&&a=='B')||(b=='B'&&a=='C')||(b=='D'&&a=='F')){
					t+=1;
				}
			}
			
		}
	}
	if(t>0){
		cout<<t;
	}
	else{
		cout<<"0000";
	}
	return 0;
}
