#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1;
	string s2;
	string c1;
	string c2;
	cin>>s1>>s2>>c1>>c2;
	if(s1==c1 && s1!="1" && s1!="16" && c1!="1" && c2!="16"){
		cout<<"1";
}
		if(s2[0]==c2[0] && s2[1]==c2[1]){
			cout<<"1";
			if(s2[2]=="F" && c2[2]=="D" || s2[2]=="D" && c2[2]=="F"){
				cout<<"11";
			}
			else if((s2[2]=="C" && c2[2]=="B") || (c2[2]=="B" && c2[2]=="C")){
				cout<<"11";
			}
			else if((s2[2]=="B" && c2[2]=="A") || (s2[2]=="A" && c2[2]=="B")){
				cout<<"11";
			}
			else if((s2[2]=="C" && c2[2]=="A") || (s[2]=="A" && c[2]=="C")){				cout<<"10";
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	cout<<"0000";
	}
	return 0;
}
