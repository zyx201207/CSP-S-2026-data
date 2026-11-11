#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char c1[2],s1[3],c2[2],s2[3],z[3];
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		z[0]='1';
	}else{
		z[0]='0';
	}
	if((s1[0]==s2[0]&&z[0]=='1')&&(s1[1]==s2[1]&&z[0]=='1')){
		z[1]='1';
	}else{
		z[1]='0';
	}
	if(z[1]=='1'&&((s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C'))||(s1[2]=='D'&&s2[2]=='F')||(s2[2]=='A'&&(s1[2]=='B'||s1[2]=='C'))||(s2[2]=='D'&&s1[2]=='F'))){
		z[2]='1';
	}else{
		z[2]='0';
	}
	if((s1[2]+1==s2[2]&&z[2]=='1')||(s1[2]-1==s2[2]&&z[2]=='1')){
		z[3]='1';
	}else{
		z[3]='0';
	}
	cout<<z;
	return 0;
}
