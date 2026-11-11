#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int s11=(int)s1[0]-48;
	int s12=(int)s1[1]-48;
	int s1a=10*s11+s12;
	int s21=(int)s2[0]-48;
	int s22=(int)s2[1]-48;
	int s2a=10*s21+s22;
	int s1b=s1[2];
	int s2b=s2[2];
	if(c1==c2){
		cout<<"1";
		if(s1a==s2a){
			cout<<"1";
			if(s1b>='D'&&s2b>='D'){
				cout<<"11";
			}else if(s1b<='C'&&s2b<='C'){
				cout<<"1";
				if(s1b-s2b==1||s1b-s2b==-1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
			
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}

