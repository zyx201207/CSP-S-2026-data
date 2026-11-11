#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
 {
	  freopen("travel.in","r",stdin);
	  freopen("travel.out","w",stdout);
	  string a1,a2,b1,b2;
	  cin>>a1>>a2>>b1>>b2;
	  if(a1[1]==b1[1]&&a1[2]==b1[2])
	     cout<<1;
	  else
	    cout<<0;
	  if(a2[1]==b2[1]&&a2[2]==b2[2])
         cout<<1;
      else
         cout<<0;
      if((a2[3]=='A'&&b2[3]=='B')||(a2[3]=='B'&&b2[3]=='A')||(a2[3]=='A'&&b2[3]=='C')||(a2[3]=='C'&&b2[3]=='B')||(a2[3]=='B'&&b2[3]=='C')||(a2[3]=='C'&&b2[3]=='A')||(a2[3]=='D'&&b2[3]=='F')||(a2[3]=='F'&&b2[3]=='D'))
        cout<<1;
      else
        cout<<0;
      if((a2[3]=='A'&&b2[3]=='B')||(a2[3]=='B'&&b2[3]=='A')||(a2[3]=='C'&&b2[3]=='B')||(a2[3]=='B'&&b2[3]=='C')||(a2[3]=='D'&&b2[3]=='F')||(a2[3]=='F'&&b2[3]=='D'))
         cout<<1;
        else
          cout<<0;
       return 0;
 }
 
