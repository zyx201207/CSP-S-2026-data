#include <iostream>
#include <cmath>
using namespace std;
int flag=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		flag=1;
	}
	else{
		cout<<"0";
		flag=0;
	}
	if(flag==0){
		cout<<"000";
		return 0;
	}
	if(s2[0]==s1[0]&&s2[1]==s1[1]){
		cout<<"1";
		flag=1;
	}
	else{
		cout<<"0";
		flag=0;
	}
	if(flag){
		if('A'<=s1[2] && 'C'>=s1[2] && 'A'<=s2[2] && 'C'>=s2[2]||'D'<=s1[2] && 'F'>=s1[2] && 'D'<=s2[2] && 'F'>=s2[2]){
			cout<<"1";
			flag=1;
		}	
		else{
			cout<<"0";
			flag=0;
		}
	}
	else{
		cout<<"0";
	}
	if(flag==0){
		cout<<"0";
	}
	else{
		if(abs((int)s1[2]-(int)s2[2])==1){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
}

