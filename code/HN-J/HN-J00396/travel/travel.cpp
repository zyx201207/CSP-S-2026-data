#include<bits/stdc++.h> 
using namespace std;
string sr,sx,s1,s2;
int c[4];
bool check(string x,string y,int s){
	int m=0;
	while(m<s){
		if(x[m]!=y[m])return 0;
		m++;
	}
	return 1;
}
bool check2(char x,char y){
	if(x<='C'&&y<='C')return 1;
	if(x>'C'&&y>'C')return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sr>>s1>>sx>>s2;
	if(check(sr,sx,2)){
		c[0]=1;
	if(check(s1,s2,2)){
		c[1]=1;
	if(check2(s1[2],s2[2])){
		c[2]=1;
	if(c[0]&&c[1]&&c[2]&&(s1[2]-1==s2[2]||s1[2]+1==s2[2])&&!(s1[2]=='D'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='D')){
		c[3]=1;
	}
	}
	}
	}
	for(int i=0;i<4;i++)cout<<c[i];
	return 0;
}
