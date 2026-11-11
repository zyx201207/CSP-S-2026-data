#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int read(){
	char c=getchar();
	int s=0,f=1;
	while(c<'0' || c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*f;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	c1=read();
	cin>>s1;
	c2=read();
	cin>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
		return 0;
	}
	int x=(s1[0]-'0')*10+(s1[1]-'0'),y=(s2[0]-'0')*10+(s2[1]-'0');
	if(x!=y){
		cout<<"1000"<<endl;
		return 0;
	}
	if( (s1[2]<='C' && s2[2]<='C') || (s1[2]>='D' && s2[2]>='D') ){
		if( abs( s1[2]-s2[2] ) == 1 ){
			cout<<"1111"<<endl;
		}else{
			cout<<"1110"<<endl;
		}
	}else{
		cout<<"1100"<<endl;
	}
}
