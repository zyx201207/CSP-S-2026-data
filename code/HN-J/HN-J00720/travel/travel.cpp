#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s1[1]){
			int a;
			if(s1[2]=='D'||s1[2]=='F'){a++;}
			if(s2[2]=='D'||s2[2]=='F'){a++;}
			if(a==2){cout<<"1111";}
			else if(a==1){cout<<"1100";}
			else{
				if(s1[2]=='B'||s2[2]=='B'){cout<<"1111";}
				else{cout<<"1110";}
			}
		}
		else{cout<<"1000";}
	}
	else{cout<<"0000";}
	return 0;
}
