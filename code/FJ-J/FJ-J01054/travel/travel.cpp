#include<bits/stdc++.h>
using namespace std;
int tx=0,tp=0,tc=0; 
int main(){
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {cout<<"1";tx=1;}
	else cout<<"0"; 
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&tx){cout<<"1";tp=1;} 
	else cout<<"0"; 
	if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'&&tx&&tp)||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'&&tx&&tp)) {cout<<"1";tc=1;}
	else cout<<"0"; 
	if(s1[2]-s2[2]==1&&tx&&tp&&tc||s1[2]-s2[2]==-1&&tx&&tp&&tc) cout<<"1";
	else cout<<"0"; 
	cout<<"\n";
	return 0;
}
