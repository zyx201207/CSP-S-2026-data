#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char a,b;
int sum;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=s1[2];
	b=s2[2];
	if((c1==c2)&&(c1!="01")&&(c1!="16"))
		cout<<1;
	else
		cout<<0;
	if((s1[0]==s2[0])&&(s1[1]==s2[1]))
		cout<<1;
	else
		cout<<0;
	if((a<='C')&&(b<='C')||((a>'C')&&(b>'C')))
		cout<<1; 
	else
		cout<<0;
	if(((a-b==1)||(b-a==1))&&(!((a=='C')&&(b=='D')||(a=='D')&&(b=='C'))))
		cout<<1;
	else
		cout<<0;
	return 0;
 } 
