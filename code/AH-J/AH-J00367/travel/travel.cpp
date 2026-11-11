#include <iostream>
#include <string>

using namespace std;

string c1,s1,c2,s2;
string l1,l2;
char a1,a2;

int main()
{
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  
  l1="",l2="";
  
  cin>>c1>>s1>>c2>>s2;
  l1+=s1[0]+s1[1],a1=s1[2],l2+=s2[0]+s2[1],a2=s2[2];
  
  if(c1!=c2)return cout<<"0000",0;
  else
  {
	  cout<<'1';
	  
	  if(l1!=l2)return cout<<"000",0;
	  else
	  {
		  cout<<'1';
		  
		  if(!(((a1=='A'||a1=='B'||a1=='C')&&(a2=='A'||a2=='B'||a2=='C'))||((a1=='D'||a1=='F')&&(a2=='D'||a2=='F'))))return cout<<"00",0;
		  else
		  {
			  cout<<'1';
			  
			  if(!(a1-a2==1||a1-a2==-1))return cout<<'0',0;
			  else cout<<'1';
		  }
	  }
  }
  
  return 0;
}
