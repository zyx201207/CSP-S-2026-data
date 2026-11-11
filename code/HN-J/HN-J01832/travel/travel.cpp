#include<bits/stdc++.h>

using namespace std;

string  c1,s1,c2,s2;
int cc1,cc2,ss1,ss2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cc1+=c1[0]-'0'+c1[1]-'0';
	cc2+=c2[0]-'0'+c2[1]-'0';
	ss1+=s1[0]-'0'+s1[1]-'0';
	ss2+=s2[0]-'0'+s2[1]-'0';
	if(cc1==cc2&&cc1!=1&&cc2!=1&&cc1!=16&&cc2!=16){
		cout<<"1";
		if(ss1==ss2){
			cout<<"1";
			if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||s1[2]>'C'&&s1[2]<='F'&&s2[2]>'C'&&s2[2]<='F'){
				cout<<"1";
				if(s1[2]-s2[2]==1||s2[2]-s1[2]==1){
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
