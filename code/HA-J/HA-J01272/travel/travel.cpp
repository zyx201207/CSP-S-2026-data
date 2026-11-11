#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,s5,s6;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	for(int i=0;i<2;i++){
		s5+=s2[i];
		s6+=s4[i];
	}
	char a,b;
	a=s2[2];
	b=s4[2];
	if(s1==s3){
		cout<<"1";
		if(s5==s6){
			cout<<"1";
			if((a<='C'&&b<='C')||(a>='D'&&b>='D')){
				cout<<"1";
				if(abs(a-b)==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
