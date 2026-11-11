#include<iostream>
using namespace std;
int a1,a2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>s1>>a2>>s2;
	if(a1!=a2){
		cout<<"0000";
	}
	else if(s1[0]!=s2[0] || s1[1]!=s2[1]){
		cout<<"1000";
	}
	else{
		char ch1=s1[2],ch2=s2[2];
		if((ch1=='F' && ch2!='D') || (ch1=='D' && ch2!='F') || (ch1=='C' && (ch2!='B' && ch2!='A')) || (ch1=='B' && (ch2!='C' && ch2!='A') || (ch1=='A' && (ch2!='B' && ch2!='C')))){
			cout<<"1100";
		}
		else{
			int cz=ch1-ch2;
			if(cz==(-1) || cz==1){
				cout<<"1111";
			}
			else cout<<"1110";
		}
	}
	return 0;
}
