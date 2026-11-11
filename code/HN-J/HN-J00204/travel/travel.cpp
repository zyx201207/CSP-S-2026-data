#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int q=1,w=1,e=1;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>c1>>s1>>c2>>s2;
if(c1==c2) cout<<1;
else {
	cout<<0;
	w=0;
}
if(!w) cout<<0;
else
{
	if(s1[0]+s1[1]==s2[0]+s2[1]) cout<<1;
	else 
	{
		cout<<0;
		e=0;
	}
}
if(w*e==0) cout<<0;
else
{
	if(s1[2]>='A'&&s1[2]<'D'&&s2[2]>='A'&&s2[2]<'D') cout<<1;
	else{
		if(s1[2]>'C'&&s1[2]<'G'&&s2[2]>='C'&&s2[2]<'G') cout<<1;
		else{
			cout<<0;
			q=0;
		} 
	}
}

if(q*w*e==0) cout<<0;
else{
	 if(s1[2]>='A'&&s1[2]<'D'&&s2[2]>='A'&&s2[2]<'D')
	 {
	 	if(s1[2]+1==s2[2]+0||s1[2]+0==s2[2]+1)cout<<1;
	 	else cout<<0;
	 }
	 else cout<<1;
}
return 0;
} 
