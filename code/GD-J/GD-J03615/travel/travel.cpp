#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool chk(char c,char t){
	if(c>='A'&&c<='C'&&t>='A'&&t<='C'){
		return 1;
	}
	if(c>='D'&&c<='E'&&t>='D'&&t<='E'){
		return 1;
	}
	return 0;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else{
		if((s1[0]!=s2[0])||(s1[1]!=s2[1])){
			cout<<"1000";
		}else{
			if(!chk(s1[2],s2[2])){
				cout<<"1100";
			}else{
				if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}
		}
	}
	return 0;
}
