#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	long long c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[1]==s2[1]&&s1[0]==s2[0]){
			cout<<"1";
			if(s1[0]=='F'){
				s1='E';
			}
			if(s2[0]=='F'){
				s2='E';
			}
			int a1=-1,a2=-1;
			if(s1[2]>'C'){
				a1+=2;
			}else{
				a1+=1;
			}
			if(s2[2]>'C'){
				a2+=2;
			}else{
				a2+=1;
			}
			if(a1==a2){
				cout<<"1";
				if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
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
//01 01A 01 01B
