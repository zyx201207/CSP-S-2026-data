#include<bits/stdc++.h>
using namespace std;
int main() {
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,x="0000";
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		x[0]='1';
	}
	if(c1==c2 and s1[0]==s2[0] and s1[1]==s2[1]){
		x[1]='1';
	}
	if((c1==c2 and s1[0]==s2[0] and s1[1]==s2[1]) and ((s1[2]<='C' and s2[2]<='C') or ((s1[2]>'C' and s2[2]>'C' and s1[2]<='F' and s2[2]<='F')))){
		x[2]='1';
	}
	if((c1==c2 and s1[0]==s2[0] and s1[1]==s2[1]) and ((s1[2]<='C' and s2[2]<='C') or (s1[2]>'C' and s2[2]>'C' and s1[2]<='F' and s2[2]<='F')) and (s1[2]-1==s2[2] or s1[2]+1==s2[2])){
		x[3]='1';
	}
	cout<<x;
	return 0;
}
