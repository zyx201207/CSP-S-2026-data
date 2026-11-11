#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1.substr(0,2)==s2.substr(0,2)){
			cout<<"1";
			if((s1.substr(2,1)<="C"&&s2.substr(2,1)<="C")||(s1.substr(2,1)>="D"&&s2.substr(2,1)>="D")){
				cout<<"1";
				if((s1.substr(2,1)>="D"&&s2.substr(2,1)>="D")||(s1.substr(2,1)=="A"&&s2.substr(2,1)=="B")||(s1.substr(2,1)=="B"&&s2.substr(2,1)=="A")||(s1.substr(2,1)=="B"&&s2.substr(2,1)=="C")||(s1.substr(2,1)=="C"&&s2.substr(2,1)=="B"))cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
