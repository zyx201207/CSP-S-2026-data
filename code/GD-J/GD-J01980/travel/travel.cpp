#include<bits/stdc++.h>
using namespace std;
string c1,c2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s3>>c2>>s4;
	if(c1==c2){
		cout<<"1";
		if(s3[0]==s4[0]&&s3[1]==s4[1]){
			cout<<"1";
			if((s3[2]>='A'&&s3[2]<='C'&&s4[2]>='A'&&s4[2]<='C')||(s3[2]>='D'&&s3[2]<='E'&&s4[2]>='D'&&s4[2]<='E')){
				cout<<"1";
				if(abs((int)s3[2]-(int)s4[2])==1){
					cout<<"1";
					return 0;
				}else{
					cout<<"0";
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
} 
