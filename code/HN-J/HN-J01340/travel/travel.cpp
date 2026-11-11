#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2,sum;
char ss1[10],ss2[10];
int main()
{
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  cin>>c1>>s1>>c2>>s2;
 if(c1==c2)
{
 cout<<"1";
 for(int i=1;i<=3;i++)
 {
 	ss1[i]=s1[i-1]-'0';
 	ss2[i]=s2[i-1]-'0';
 }
 if(ss1[1]==ss2[1]&&ss1[2]==ss2[2])
 {
 	cout<<"1";
if(int(ss1[3])<=19&&int(ss2[3])<=19) 
 {
 cout<<"1";
 	if(abs(int(ss1[3])-int(ss2[3]))==1)
 	cout<<"1";
 	else
 	cout<<"0";
 }
 else if(int(ss1[3])>19&&int(ss2[3])>19) 
 {
 	cout<<"11";
 }
 else
 cout<<"00";	
 }
 else
 cout<<"000";	
 
 }
 else
 cout<<"0000";
	return 0;
}
