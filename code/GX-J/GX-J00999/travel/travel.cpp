#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
string c1,s1,c2,s2;
char a1,a2;
int num1,num2;
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=2;i++)
	{
	  if(s1[i]>='0'&&s1[i]<='9')
	    num1=num1*10+s1[i]-'0';
	  if(s2[i]>='0'&&s2[i]<='9')
	    num2=num2*10+s2[i]-'0';
	}
	if(c1==c2)
	{
	  cout<<"1";
	  if(num1==num2)
	  {
	    cout<<"1";
	    if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')
	    {
	      cout<<"1";
	      if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B'))
	        cout<<"1";
	      else
	        cout<<"0";
	    }
	    else 
	    {
	      if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')
	        cout<<"11";
	      else
	        cout<<"00";
	    }
	    
	  }
	  else
	    cout<<"000";
	}
	else
      cout<<"0000";
    return 0;
}
