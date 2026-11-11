#include<iostream>
using namespace std;
char c1,s1[3],c2,s2[3];
int main() {
freopen("travel.in","r","stdin");
freopen("travel.out","w","stdout");
    cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";	
	}else{
		cout<<"1";
		if(s1[2]!=s2[2]){
			cout<<"000";
			}else{
			cout<<"1";
			if(s1[3]!=s2[3]){
				cout<<"00";
			}else{
				cout<<"1";
					
			}
		}
	}
	
	return 0;
}
	
