#include<bits/stdc++.h>
using namespace std;
string c,s,c1,s1,t,t1;
char v,v1;
int f=0,g=0,p=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c1>>s1;
	t=s[0]+s[1];
	t1=s1[0]+s1[1];
	v=s[2];
	v1=s1[2];
	if(c==c1)cout<<1;
	if(c!=c1)cout<<0;
	if(t==t1&&c==c1){
		cout<<1;
		p=1;
	}
	if(t!=t1||c!=c1)cout<<0;
	if((v>='A'&&v<='C'&&v1>='A'&&v1<='C'&&p)||(v>='D'&&v1<='F'&&v1>='D'&&v1<='F'&&p)){
		f=1;
	}
	if(f==1)cout<<1;
	if(f==0)cout<<0;
	if(f==1&&(v-v1==1||v1-v==1))g=1;
	if(g==1)cout<<1;
	if(g==0)cout<<0;
	return 0; 
} 
