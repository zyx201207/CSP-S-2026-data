#include<bits/stdc++.h>
using namespace std;
int n,m;
string c1,c2,s1,s2;
bool pd()
{
	if((s1[2]=='E'||s1[2]=='F')&&(s2[2]=='E'||s2[2]=='F'))
	 return true;
	if((s1[2]=='A'||s1[2]=='B')&&(s2[2]=='A'||s2[2]=='B'))
	 return true;
	if((s1[2]=='B'||s1[2]=='C')&&(s2[2]=='B'||s2[2]=='C'))
	 return true;
	return false;
 } 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool f=false;
	if(c1==c2)
	 cout<<1;
	else
	 f=true,cout<<0;
	if(f==false&&s1[0]==s2[0]&&s1[1]==s2[1])
	 cout<<1;
	else
	 f=true,cout<<0;
	if(f==false&&((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='E'||s1[2]=='F')&&(s2[2]=='F'||s2[2]=='E')))
	 cout<<1;
	else
	 f=true,cout<<0;
	if(f==true)
	{
		cout<<0;
		return 0;
	}
	if(pd()==true)
	 cout<<1;
	else
	 cout<<0;
	return 0;
} 
