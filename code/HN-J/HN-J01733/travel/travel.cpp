#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
 string c1,c2,c3,c4;
 char s1,s2;
 string c5=c2+s1;
 string c6=c4+s2;
 cin>>c1>>c5>>c3>>c6;
	if(c1==c3){
		cout<<"1";
		if(c2==c4){
			cout<<"1";
			if(s1<='C'&&s2<='C'){
				cout<<"1";
				if(s1-s2==1||s2-s1==1){
					cout<<"1";
		}
					else{
						cout<<"0";
					}
				
		}
		else if(s1>'C'&&s2>'C'){
				cout<<"11";
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
