#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		int c=(s1[0]-'0')*10+s1[1]-'0';
		int s=(s2[0]-'0')*10+s2[1]-'0';
		if(c==s){
			cout<<"1";
			int cw=s1[2]-'A'+1;
			int sw=s2[2]-'A'+1;
			if(((cw>=1&&cw<=3)&&(sw>=1&&sw<=3))||((cw>=4&&cw<=5)&&(sw>=4&&sw<=5))){
				cout<<"1";
				if(cw-1==sw||cw+1==sw){
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
