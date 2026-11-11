#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int c,cc,s,ss,a1,a2;
void f(){
	if(s1[2]<'D' && s2[2]<'D'){
		cout<<1;
		if(char(s1[2]+1)==s2[2] || char(s2[2]+1)==s1[2])cout<<1<<endl;
		else cout<<0<<endl;
	}
	else if(s1[2]>='D' && s2[2]>='D'){
		cout<<1;
		if(char(s1[2]+1)==s2[2] || char(s2[2]+1)==s1[2])cout<<1<<endl;
		else cout<<0<<endl;
	}
	else cout<<0<<0<<endl;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	c=(c1[1]-'0')*10+c1[0]-'0';
	cc=(c2[1]-'0')*10+c2[0]-'0';
	s=(s1[1]-'0')*10+s1[0]-'0';
	ss=(s2[1]-'0')*10+s2[0]-'0';
	if(c==cc){
		cout<<1;
		if(s==ss){
			cout<<1;
			f();
		}
		else cout<<0<<0<<0<<endl;
	}
	else cout<<0<<0<<0<<0<<endl;
	
	
	return 0;
}
