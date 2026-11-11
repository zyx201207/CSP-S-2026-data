#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	long long a1=(c1[0]-'0')*10+(c1[1]-'0'),a2=(c2[0]-'0')*10+(c2[1]-'0');
	if(a1==a2)cout<<1;
	else cout<<0;
	string b1="",b2="";
	b1+=s1[0],b1+=s1[1],b2+=s2[0],b2+=s2[1];
	if(b1==b2&&a1==a2)cout<<1;
	else cout<<0;
	bool p1=0,p2=0;
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'&&b1==b2&&a1==a2)cout<<1,p1=1;
	else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'&&b1==b2&&a1==a2)cout<<1,p2=1;
	else cout<<0;
	if(p1||p2){
		if(abs(s1[2]-s2[2])==1)cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
