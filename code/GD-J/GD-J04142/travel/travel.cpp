#include<bits/stdc++.h>
using namespace std;
char c[2],cc[3],s[2],ss[3];
int m,n;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<2;++i)cin>>c[i];
	for(int i=0;i<3;++i)cin>>cc[i];
	for(int i=0;i<2;++i)cin>>s[i];
	for(int i=0;i<3;++i)cin>>ss[i];
	m=c[1]-'0';
	n=s[1]-'0';
	if(c[0]=='1')m+=10;
	if(s[0]=='1')n+=10;
	if(m!=n){
		cout<<"0000";
		return 0;
	}
	m=cc[1]-'0';
	n=ss[1]-'0';
	if(cc[0]=='1')m+=10;
	if(ss[0]=='1')n+=10;
	if(m!=n){
		cout<<"1000";
		return 0;
	}
	m=cc[2]-'A'+1;
	n=ss[2]-'A'+1;
	if((m>3&&n<=3)||(m<=3&&n>3)){
		cout<<"1100";
		return 0;
	}
	if(abs(m-n)!=1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
