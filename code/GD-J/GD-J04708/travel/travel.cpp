#include<iostream>
#include<cmath>
using namespace std;
string c1,s1,c2,s2; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		cout<<1;
	else
		cout<<0;
	int t1=0,t2=0;
	for(int i=0;i<2;i++)
		t1=t1*10+s1[i]-'0';
	for(int i=0;i<2;i++)
		t2=t2*10+s2[i]-'0';
	if(c1==c2&&t1==t2)
		cout<<1;
	else
		cout<<0;
	if(c1==c2&&t1==t2&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')))
		cout<<1;
	else
		cout<<0;
	if(c1==c2&&t1==t2&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))&&abs(s1[2]-s2[2])==1)
		cout<<1;
	else
		cout<<0;
} 
