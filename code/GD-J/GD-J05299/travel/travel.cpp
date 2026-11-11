#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    getline(cin,c1);
    getline(cin,s1);
    getline(cin,c2);
    getline(cin,s2);
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if((int(s1[2]-'A')/3==0&&int(s2[2]-'A')/3==0)||(int(s1[2]-'A')/3==1&&int(s2[2]-'A')/3==1)){
	cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
    if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
		cout<<"1";
	}
	else cout<<"0";
	return 0;
} 
