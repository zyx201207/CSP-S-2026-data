#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   int s1[3],s2[3];
   if(c1==c2)
   {
	   cout<<1-'0';
   }
   else if(c1!=c2)
   {
	   cout<<'0'<<'0'<<'0'<<'0';
   }  
   if(s1[1]==s2[1]&&s1[2]==s2[2])
   {
	   cout<<1-'0';
   }
   else
   {
	         
	    cout<<0-'0';
   }
   if(((s1[3]>='64'&&s1[3]<='66')&&(s2[3]>='64'&&s2[3]<='66'))||(s1[3]>='67'&&s1[3]<='68')&&(s2[3]>='67'&&s2[3]<='68')
   {
	    cout<<1-'0'<<1-'0';
   }
   else
   {
	    cout<<0-'0'<<0-'0';
   }   
   return 0;
}
