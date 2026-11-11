#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<"1";
		if(s2[0]==s4[0] and s4[1]==s2[1]){
			cout<<"1";
			if((s2[2]<='C' and s4[2]<='C')or(s2[2]>'C'&&s4[2]>'C')){
				cout<<"1";
				int a=abs(s2[2]-s4[2]);
				if((s2[2]+s4[2]!='C'+'D' and a==1) or(s2[2]=='D' and s4[2]=='F') or(s2[2]=='F' and s4[2]=='D')){
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
	
	return 0;
}
