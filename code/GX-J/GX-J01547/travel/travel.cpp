#include<bits/stdc++.h>
using namespace std;
int main()
{
  //freopen("travel.out","r",stdin);
  //freopen("travel.in","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  char a,b,c,d,e,f,g,h,i,j;//02 01A 02 01B
  cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j;
  if(a==f&&b==g) 
  {
    cout<<"1";
    if(c==h&&d==i) 
    {
	    cout<<"1";
	    if((e>='D'&&j>='D')||(e<='C'&&j<='C'))
	    {
        cout<<"1";
        if((e==j-1)||(e==j+1))
        {
				  cout<<"1";	
				}
				else cout<<"0";
			}
			else cout<<"00";	
	  }
    else cout<<"000";	
	}
  else cout<<"0000";
  return 0;
}
