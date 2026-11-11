#include <bits/stdc++.h>
using namespace std;
int a,c;
string b,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}else if(a==c){
		cout<<"1";
		if(b[0]==d[0]&&b[1]==d[1]){
		cout<<"1";
			char cmpb=b[2],cmpd=d[2];
			cmpb=cmpb-'A'+1;
			cmpd=cmpd-'A'+1;
			if(cmpb+cmpd==10){
				cout<<"11";
			}else if(cmpb+cmpd==3){
				cout<<"11";
			}else if(cmpb+cmpd==4){
				cout<<"10";
			}else if(cmpb+cmpd==5){
				if(cmpb==4||cmpd==4){
					cout<<"00";
				}else{
					cout<<"11";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	} 
	return 0;
} 
