#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2; 
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";	
		return 0;
	}
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]) b=1;
	}
	if(b==0) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(s1[2]<='C'&&s2[2]>='D'||(s2[2]<='C'&&s1[2]>='D')){
		cout<<"00";
		return 0;
	}
	if(s1[2]<='C'&&s1[2]<='C'||(s1[2]>'C'&&s1[2]>'C')) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(s1[2]-s2[2])==1) cout<<"1";
	else cout<<"0";
	return 0;
}
//Trick||Treat!
//02 01C 02 01D
