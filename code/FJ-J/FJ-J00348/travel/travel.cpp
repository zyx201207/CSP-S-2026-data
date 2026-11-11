#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1.substr(0,2)==s2.substr(0,2)){
			cout<<1;
			if(s1[2]=='F'||s1[2]=='D'){
				if(s2[2]=='F'||s2[2]=='D'){
					cout<<"11";
				}else{
					cout<<"00";
				}
			}else{
				if(s2[2]=='F'||s2[2]=='D'){
					cout<<"00";
				}else{
					cout<<"1";
					if(abs(s2[2]-s1[2])==1){
						cout<<"1";
					}else{
						cout<<0;
					}
				}
		}
		}else{
			cout<<"000";
		}
		
	}else{
		cout<<"0000"<<endl;
	}
	
	return 0;
} 
