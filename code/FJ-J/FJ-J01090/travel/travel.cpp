#include<bits/stdc++.h>
using namespace std;
string c[4],a,b;
char s[4]={'0','0','0','0'},d,e;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<4;i++) cin>>c[i];
	a+=c[1][0];
	a+=c[1][1];
	b+=c[3][0];
	b+=c[3][1];
	if(c[0]==c[2]){
	s[0]='1';
	if(a==b){
	s[1]='1';
	if((c[1][2]-65<3)==(c[3][2]-65<3)){
	s[2]='1';
	if(abs(c[1][2]-c[3][2])==1) s[3]='1';
}
}
}
	for(int i=0;i<4;i++) cout<<s[i];
	cout<<endl;
	return 0;
}
