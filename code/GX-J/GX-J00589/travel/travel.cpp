#include<bits/stdc++.h>
using namespace std;
int c1,c2,a1,a2;
char b1,b2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1;
	cin>>c2>>s2;
	for(int i=0;i<(int)s1.size();i++){
		if(s1[i]>='0'&&s1[i]<='9')a1=a1*10+int(s1[i]-'0');
	}
	for(int i=0;i<(int)s2.size();i++){
		if(s2[i]>='0'&&s2[i]<='9')a2=a2*10+int(s2[i]-'0');
	}
	b1=s1[s1.size()-1];
	b2=s2[s2.size()-1];
	if(c1==c2)cout<<1;
	else cout<<0;
	if(c1==c2&&a1==a2)cout<<1;
	else cout<<0;
	if(c1==c2&&a1==a2&&((b1<='C'&&b2<='C')||(b1>='D'&&b2>='D')))cout<<1;
	else cout<<0;
	if(c1==c2&&a1==a2&&((b1<='C'&&b2<='C')||(b1>='D'&&b2>='D'))&&(abs(b1-b2)<=1||(b1=='D'&&b2=='F')||(b1=='F'||b2=='D')))cout<<1;
	else cout<<0;
	return 0;
}
