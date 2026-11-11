#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,z1,s2,z2;
	cin>>s1>>z1>>s2>>z2;
	if(s1==s2){
		cout<<"1";
		if(z1[0]==z2[0]&&z1[1]==z2[1]){
			cout<<"1";
			if((z1[2]=='A'&&z2[2]=='B')||(z1[2]=='B'&&z2[2]=='A')||(z1[2]=='B'&&z2[2]=='C')||(z1[2]=='C'&&z2[2]=='B')||(z1[2]=='D'&&z2[2]=='F')||(z1[2]=='F'&&z2[2]=='D')){
				cout<<"11";
			}else if((z1[2]=='A'&&z2[2]=='C')||(z1[2]=='C'&&z2[2]=='A')){
				cout<<"10";
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
