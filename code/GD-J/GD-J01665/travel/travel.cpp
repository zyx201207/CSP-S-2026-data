#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ss="",t1,t2;
bool b1,b2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2)	ss+='1';					//车厢
	else	ss+='0';
	
	t1=s1[0]+s1[1],t2=s2[0]+s2[1];			//同一排
	if(ss[0]=='1'&&t1==t2)	ss+='1';
	else	ss+='0';
	
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')	//同一侧 
		b1=1;
	else	b1=0;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
		b2=1;
	else	b2=0;
	if(ss[1]=='1'&&b1==b2)	ss+='1';
	else	ss+='0';
	
	if(ss[2]=='1'&&abs(s1[2]-s2[2])==1)		//相邻
		ss+='1';
	else	ss+='0';
	 
	cout<<ss;
	
	return 0;
}
