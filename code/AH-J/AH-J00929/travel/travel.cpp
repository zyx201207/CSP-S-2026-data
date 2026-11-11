#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string a,b,c,d,s1,s2,s;
cin>>a>>s1>>b>>s2;
for(int i=0;i<2;i++){
	c+=s1[i];
	d+=s2[i];
}
if(a==b){
	s+='1';
	if(c==d){
		s+='1';
		if(max(s1[2],s2[2])<='C'||min(s1[2],s2[2])>'C'){
			s+='1';
			if(abs(s1[2]-s2[2])==1){
				s+='1';
			}
			else{
				s+='0';
			}
		}
		else{
			s+="00";
		}
	}
	else{
		s+="000";
	}
}
else{
	s+="0000";
}
cout<<s;
	return 0;
}
