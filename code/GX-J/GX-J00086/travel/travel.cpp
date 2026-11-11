#include<iostream>
#include<math.h>
using namespace std;
string r1,r2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>r1>>s1>>r2>>s2;
	if(r1==r2){
		cout<<"1";
		if(s1.substr(0,2)==s2.substr(0,2)){
			cout<<"1";
			if(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C'){
				cout<<"1";
				cout<<(abs(s1[2]-s2[2])==1);
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	
	return 0;
}
