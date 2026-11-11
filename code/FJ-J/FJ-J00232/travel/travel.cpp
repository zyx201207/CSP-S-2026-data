#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,r="";
int c_1,c_2;
int s2i(string s){
	int i=0;
	for(int j=0;j<s.length();j++){
		i=i*10+(s[j]-'0');
	}
	return i;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	c_1=s2i(c1);
	c_2=s2i(c2);
	if(c_1==c_2){
		r+="1";
		if((s1[0]+s1[1])==(s2[0]+s2[1])){
			r+="1";
			if(((s1[2]>='A')&&(s1[2]<='C')&&(s2[2]>='A')&&(s2[2]<='C'))){
				r+="1";
				if((int(s1[2]-s2[2])==1)||(int(s2[2]-s1[2])==1)) r+="1";
				else r+="0";
			}
			else if(((s1[2]>='D')&&(s1[2]<='F')&&(s2[2]>='D')&&(s2[2]<='F'))) r+="11";
			else r+="00";
		}
		else r+="000";
	}
	else r="0000";
	cout<<r;
	return 0;
}
