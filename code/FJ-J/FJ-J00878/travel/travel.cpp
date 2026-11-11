#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool a=false,b=false,c=false;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		c=true;
	}
	else cout<<0;
	if(!c) cout<<0;
	else if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		b=true;
	}
	else cout<<0;
	if(!b) cout<<0;
	else if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D'){
		cout<<1;
		a=true;
	}
	else cout<<0;
	if(!a) cout<<0;
	else if(s1[2]-1==s2[2]||s1[2]+1==s2[2]) cout<<1;
	else if(s1[2]>='D'&&s2[2]>='D') cout<<1;
	else cout<<0;
	return 0;
 } 
