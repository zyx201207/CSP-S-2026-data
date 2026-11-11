#include<bits/stdc++.h>
using namespace std;
string str1,str2,str3,str4;
bool r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>str1>>str2>>str3>>str4;
	if(str1!=str3){
		cout<<"0000";
	}
	else{
		if(str2[0]!=str4[0]||str2[1]!=str4[1]){
			cout<<"1000";
		}
		else{
			if(str2[2]>='A'&&str2[2]<='C'){
				r=1;
			}
			else{
				r=0;
			}
			if(str4[2]>='A'&&str4[2]<='C'){
				x=1;
			}
			else{
				x=0;
			}
			if(r!=x){
				cout<<"1100";
			}
			else{
				if((str4[2]=='A'&&str2[2]=='C')||(str2[2]=='A'&&str4[2]=='C')){
					cout<<"1110";
				}
				else{
					cout<<"1111";
				}
			}
		}
	}
	return 0;
}
