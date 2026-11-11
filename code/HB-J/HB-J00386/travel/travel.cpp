#include <bits/stdc++.h>

using namespace std;

string c1,s1,c2,s2;

bool check(char x,char y){
	if((x=='A'||x=='B'||x=='C')&&(y=='A'||y=='B'||y=='C')) return true;
	if((x=='D'||x=='F')&&(y=='D'||y=='F')) return true;
	return false;
}

bool check2(char x,char y){
	if((x=='A'&&y=='B')||(x=='B'&&y=='A')) return true;
	if((x=='B'&&y=='C')||(x=='C'&&y=='B')) return true;
	if((x=='D'&&y=='F')||(x=='F'&&y=='D')) return true;
	return false;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			char ca=s1[2],cb=s2[2];
			if(check(ca,cb)){
				if(check2(ca,cb)){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
			else{
				cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
