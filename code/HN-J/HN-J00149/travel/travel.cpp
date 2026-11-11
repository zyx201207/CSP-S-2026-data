#include<bits/stdc++.h>
using namespace std;
//#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<"1";
		if(s2.substr(0,2)==s4.substr(0,2)){
			cout<<"1";
			int t1=s2[2]-'A'+1,t2=s4[2]-'A'+1;
			if((t1==1&&t2==2)||(t1==2&&t2==1)||(t1==1&&t2==3)||(t1==3&&t2==1)||(t1==2&&t2==3)||(t1==3&&t2==2)||(t1==4&&t2==6)||(t1==6&&t2==4)){
				cout<<"1";
				if((t1==1&&t2==2)||(t1==2&&t2==1)||(t1==2&&t2==3)||(t1==3&&t2==2)||(t1==4&&t2==6)||(t1==6&&t2==4)){
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
