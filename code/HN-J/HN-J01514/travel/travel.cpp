#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(s1[0]==s1[1]!=0&&s2[0]==s2[1]!=0&&s1[2]!='E'&&s2[2]!='E'){
		if(c1>="02"&&c2>="02"&&c1<="15"&&c2<="15"&&s1!=s2&&s1[0]<='1'&&s2[0]<='1'&&s1[0]>='0'&&s2[0]>='0'&&s1[1]>='0'&&s2[1]>='0'&&s1[1]<='18'&&s2[1]<='18'){
			if(c1==c2){
				cout<<"1";
				if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]>='A'&&s1[2]<='F'&&s2[2]>='A'&&s2[2]<='F'){
					cout<<"1";
					if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D'){
						cout<<"1";
						if(s1[2]==s2[2]+1||s1[2]==s2[2]-1){
							cout<<"1";
						}else if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'){
							cout<<"1";
						}else{
							cout<<"0";
						}
					}else{
						cout<<"00";
					}
				}else{
					cout<<"000";
				}
			}else{
				cout<<"0000";
			}
		}else{
			cout<<"0000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
