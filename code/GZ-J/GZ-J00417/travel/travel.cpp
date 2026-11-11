//GZ-J00417 中天中学 王斓锡
#include<bits/stdc++.h>
using namespace std;
 string c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=4;i++){
			cin>>c1>>s1>>c2>>s2;
			}
				
		for(int i=1;i=1;i++){
			if(c1[i]==c2[i]){
				cout<<"1";
				if(s1[0]==s2[0]&&s1[1]==s2[1]){
					cout<<"1";
					if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
						cout<<"1";
						if(abs(s1[2]-s2[2])==1){
							cout<<"1";
						}
						else{
							cout<<"0";
						}
					}
					else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
						cout<<"11";
					}
					else if(s1[2]=='C'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='C'){
						cout<<"00";
					}
				}
				else{
					cout<<"000";
				}
				break;
			}
			else{
				cout<<"0000";
				break;
		}
	}
	return 0;
}
