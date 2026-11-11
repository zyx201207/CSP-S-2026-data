#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","W",stdout);
	string c1,s1,c2,s2;
	string s11,s21;
	char s12,s22;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		int i,j;
		for(i=0;i<1;i++){
			s11+=s1[i];
		}
		s12=s1[2];
		for(int j=0;j<1;j++){
			s21+=s2[j];
		}
		s22=s2[2];
		if(s11==s21){
			cout<<"1";
			if((s12<='C'&&s22<='C')||((s12=='F'&&s22=='D')||(s12=='D'&&s22=='F'))){
				cout<<"1";
				if(((s12=='F'&&s22=='D')||(s12=='D'&&s22=='F'))||(s12=='A'&&s22=='B')||(s12=='B'&&s22=='A')||(s12=='A'&&s22=='C')||(s12=='C'&&s22=='A')||((s12=='C'&&s22=='B')||(s12=='B'&&s22=='C'))){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
