#include<bits/stdc++.h>
#include<cstdio>
using namespace std; 
int f[4]={0,0,0,0};
string s[2],c[2];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s[0]>>s[1]>>c[0]>>c[1];
	if(abs(s[1][2]-c[1][2])==1)f[3]=1;
	if(s[1][2]<='C'&&c[1][2]<='C'||s[1][2]>='D'&&c[1][2]>='D')f[2]=1;
	else f[3]=0;
	if(s[1][0]==c[1][0]&&s[1][1]==c[1][1])f[1]=1;
	else{
		f[2]=0,f[3]=0;
	}
	if(s[0]==c[0])f[0]=1;
	else {
		f[1]=0;
		f[2]=0;
		f[3]=0;
	}cout<<f[0]<<f[1]<<f[2]<<f[3];		
	return 0;
}
