//GZ-J00440 遵义市第四中学 杨宜炜
#include<bits/stdc++.h>
using namespace std;
string s,s1,s2,s3;
int main(){
	freopen("travel.in"."r",stdin);
	freopen("travel.out"."w",stdout);
	cin>>s>>s1>>s2>>s3;
	if(s==s2){
		cout<<"1";
		if(s1[1]==s3[1]&&s1[0]==s3[0]){
			cout<<"1";
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
				if(s3[2]=='D'||s3[2]=='F'){
					cout<<"00";
				}else{
					cout<<"1";
					if(s1[2]=='A'&&s3[2]=='C'){
						cout<<"0";
					}else if(s1[2]=='C'&&s3[2]=='A'){
						cout<<"0";
					}else{
						cout<<"1";
					}
				}
			}else if(s3[2]=='A'||s3[2]=='B'||s3[2]=='C'){
				if(s1[2]=='D'||s1[2]=='F'){
					cout<<"00";
				}else{
					cout<<"1";
					if(s1[2]=='A'&&s3[2]=='C'){
						cout<<"0";
					}else if(s1[2]=='C'&&s3[2]=='A'){
						cout<<"0";
					}else{
						cout<<"1";
					}
				}
			}else{
				cout<<"1";
				if(s1[2]=='A'&&s3[2]=='C'){
					cout<<"0";
				}else if(s1[2]=='C'&&s3[2]=='A'){
					cout<<"0";
				}else{
					cout<<"1";
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
}
