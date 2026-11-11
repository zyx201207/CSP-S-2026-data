#include<iostream>
using namespace std;
string c1,s1,c2,s2;
bool ans=1;
int abs(int x){
	if(x>=0) return x;
	else return -x; 
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else return cout<<"0000",0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<"1";
	else return cout<<"000",0;
	if(s1[2]<='C'&&s2[2]<='C')
		if(abs(s1[2]-s2[2])==1) cout<<"11";
		else cout<<"10";
	else if(s1[2]>'C'&&s2[2]>'C')
		cout<<"11";
	else cout<<"00";
	return 0;
}
