#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
string s1,z1,s2,z2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>z1>>s2>>z2;
	if(s1==s2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(z1[0]==z2[0]&&z1[1]==z2[1]){
		cout<<"1";
		if(z1[2]<='C'&&z2[2]<='C'){
			cout<<"1";
			if(z1[2]=='A'&&z2[2]=='B'||z1[2]=='B'&&z2[2]=='A'||z1[2]=='B'&&z2[2]=='C'||z1[2]=='C'&&z2[2]=='B'){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else if(z1[2]>='D'&&z2[2]>='D'){
			cout<<"11";
		}else{
			cout<<"00";
		}
	}else{
		cout<<"000";
	}
	return 0;
}
