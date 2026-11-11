#include<cstdio> 
#include<iostream>
using namespace std;
string c1,s1,c2,s2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	int l1=(c1[0]-'0')*10+c1[1]-'0',l2=(c2[0]-'0')*10+c2[1]-'0';
	if(l1==l2)cout<<1;
	else cout<<0;
	int l3=(s1[0]-'0')*10+s1[1]-'0';
	int l4=(s2[0]-'0')*10+s2[1]-'0';
	if(l3==l4&&l1==l2)cout<<1;
	else cout<<0;
	
	if(l3==l4&&l1==l2&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')))cout<<1;
	else cout<<0;
	
	if(l3==l4&&l1==l2&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')))cout<<1;
	else cout<<0;
}
