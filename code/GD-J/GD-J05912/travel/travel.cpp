#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,str1,str2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else cout<<"0";
	str1+=s1[0],str1+=s1[1],str2+=s2[0],str2+=s2[1];
	if(c1==c2&&str1==str2) cout<<"1";
	else cout<<"000";
	if((c1==c2)&&(str1==str2)&&(s1[2]>='A'&&s1[2]<='C')){
		if(s2[2]>='A'&&s2[2]<='C'){
			cout<<"1";
			if(abs(int(s1[2]-s2[2]))==1) cout<<"1";
			else cout<<"0";
		}
		else cout<<"00";
	}
	else if((c1==c2)&&(str1==str2)&&(s1[2]=='D'||s1[2]=='F')){
		if(s2[2]=='D'||s2[2]=='F') cout<<"11";
		else cout<<"00";
	}
	return 0;
}
