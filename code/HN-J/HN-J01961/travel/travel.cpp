#include<bits/stdc++.h>
using namespace std;
int main()
{  freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   string c1,s1,c2,s2;
   int flag=0;
   cin>>c1;
   cin>>s1;
   cin>>c2;
   cin>>s2;
   if(c1[0]!=c2[0]||c1[1]!=c2[1])
   {
   	cout<<"0000";
   	return 0;
   }
   cout<<"1";
   for(int i=0;i<2;i++)
   {
        if(s1[i]==s2[i])
        {
        	flag++;
		}
   }
   if(flag==2)
   {
   	   cout<<"1";
   	   if(s1[2]=='A'&&s2[2]=='B')  cout<<"11";
   	   else if(s1[2]=='B'&&s2[2]=='A')  cout<<"11";
   	   else if(s1[2]=='C'&&s2[2]=='B')  cout<<"11";
   	   else if(s1[2]=='B'&&s2[2]=='C')  cout<<"11";
   	   else if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))  cout<<"11";
	   else cout<<"00"; 
   } 
   else cout<<"000";
return 0;
}

