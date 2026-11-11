#include<bits/stdc++.h>
using namespace std;
#define intl long long
string a,b,c,d;
bool f[4]={0,0,0,0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,s1;
	cin>>a>>b>>c>>d;
	char s2,s3;
	s=a.substr(0,2);
	s1=c.substr(0,2);
	s2=b[2];
	s3=d[2];
	if(a==c){
		f[0]=1;
		if(s==s1){
			 f[1]=1;
			 if((s2<='C'&&s3<='C')||(s2>'C'&&s3>'C')){
			 	f[2]=1;
			 	if(char(s2+1)==s3||char(s3+1)==s2) f[3]=1;
			 }
		}
	}
	cout<<f[0]<<f[1]<<f[2]<<f[3];
	return 0;
} 
