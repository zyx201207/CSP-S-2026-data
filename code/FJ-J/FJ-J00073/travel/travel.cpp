#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
char x,y;
int a1,b1,a2,b2;
bool b=true;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a1=(c1[0]-'0')*10+(c1[1]-'0');
	a2=(c2[0]-'0')*10+(c2[1]-'0');
	b1=(s1[0]-'0')*10+(s1[1]-'0');
	b2=(s2[0]-'0')*10+(s2[1]-'0');
	x=s1[2];
	y=s2[2];
	if(x=='F')x='E';
	if(y=='F')y='E';
	if(a1==a2)cout<<1;
	else{
		cout<<0;
		b=false;
	}
	if(b&&b1==b2)cout<<1;
	else{
		cout<<0;
		b=false;
	}
	if(b&&((x<='C'&&y<='C')||(x>'C'&&y>'C')))cout<<1;
	else{
		cout<<0;
		b=false;
	}
	if(b&&(y==x+1||x==y+1))cout<<1;
	else cout<<0;
	return 0;
}
