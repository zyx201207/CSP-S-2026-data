#include <bits/stdc++.h>
using namespace std;
int n[3];
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2 && c1!="01" && c1!="16"){
		n[0]=1;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		n[1]=1;
	}
	if(s1[2]<='C' && s2[2]<='C' || s1[2]>'C' && s2[2]>'C'){
		n[2]=1;
	}
	if(s1[2]+'1'-'0'==s2[2] || s1[2]-'1'+'0'==s2[2]){
		n[3]=1;
	}
	for(int i=0;i<=3;i++){
		cout<<n[i];
	}
	return 0;
}
