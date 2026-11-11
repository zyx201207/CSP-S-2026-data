#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	char s10=s1[0];
	char s11=s1[1];
	int s10i=s10-48;
	int s11i=s11-48;
	int s101i=s10i*10+s11i;
	
	char s20=s2[0];
	char s21=s2[1];
	int s20i=s20-48;
	int s21i=s21-48;
	int s201i=s20i*10+s21i;
	
	char s12=s1[2];
	char s22=s2[2];
	
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		if(s1[2]=='A' && s2[2]=='B' || s1[2]=='A' && s2[2]=='C' || s1[2]=='B' && s2[2]=='A' || s1[2]=='B' && s2[2]=='C' || s1[2]=='C' && s2[2]=='A' || s1[2]=='C' && s2[2]=='B' || s1[2]=='D' && s2[2]=='F' || s1[2]=='F' && s2[2]=='D'){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	
	if(s10i!=0&&s20i!=0){
		if(s101i==s201i){
			if(s12=='A' && s22=='B' || s12=='B' && s22=='A' || s12=='B' && s22=='C' || s12=='C' && s22=='B' || s12=='D' && s22=='F' || s12=='F' && s22=='D'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			if(s12==s22){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}
	}else if(s10i!=0||s20i!=0){
		if(s12==s22){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		if(s11i==s21i){
			if(s12=='A' && s22=='B' || s12=='B' && s22=='A' || s12=='B' && s22=='C' || s12=='C' && s22=='B' || s12=='D' && s22=='F' || s12=='F' && s22=='D'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			if(s12==s22){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}
	}
	return 0;
}
