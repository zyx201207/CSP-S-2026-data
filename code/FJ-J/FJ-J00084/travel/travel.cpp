#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,f,g;
string s,t;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>t;
	c=s[0]*10+s[1];
	d=t[0]*10+t[1];
	f=s[2]-'A';
	g=t[2]-'A';
	if(a==b) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(c==d) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((f==0&&(g==1||g==2))||(f==1&&(g==0||g==2))||(f==2&&(g==1||g==0))||(f==3&&g==4)||(f==4&&g==3)) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if((f==0&&g==1)||(f==1&&g==0)||(f==1&&g==2)||(f==2&&g==1)||(f==3&&g==4)||(f==4&&g==3)) cout<<1;
	else cout<<0;
	return 0;
}
//I love litelisi
