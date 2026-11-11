#include<iostream>
using namespace std;
int main()
{
   freopen("travel.in","r",stdin);
   freopen("trawel.out","w",stdout);
   string s1,s2,c1,c2,j;
   cin>>c1>>s1>>c2>>s2;
   if(s1<s2)
   {
	   j=s2;
	   s2=s1;
	   s1=j;
   }   
   if(c1==c2)
   {
	   if(s1[0]==s2[0] && s1[1]==s2[1])
	   {
		 if((s1[2]<='C' && s2[2]<='C') || (s1[2]>='D' && s2[2]>='D'))
		 {
			 if((s1[2]<='C' && s2[2]<='C' && s1[2]==s2[1]+1) || (s1[2]>='D' && s2[2]>='D'))
			 {
				 cout<<"1111";
			}
		 }	
		 else cout<<"1100";  
	   }
	   else cout<<"1000" ;  
   }
   else cout<<"0000";
   return 0;
 }
