#include<bits/stdc++.h>

using namespace std;

string c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		string str1,str2;
		char st1,st2;
		str1+=s1[0];str1+=s1[1];
		str2+=s2[0];str2+=s2[1];
		st1=s1[2];st2=s2[2];
		if(str1==str2){
			cout<<"1";
			if((st1<='C'&&st2<='C')||(st1>'C')&&st2>'C'){
				cout<<"1";
				if((st1=='D'&&st2=='F')||(st1=='F'&&st2=='D')||(st1-st2==1)||(st2-st1==1)){
					cout<<"1";
				}
				else cout<<"0"; 
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}
