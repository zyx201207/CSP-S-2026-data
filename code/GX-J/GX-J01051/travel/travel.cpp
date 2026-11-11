#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<set>
#include<stack>
#include<string>
#include<cstring>
using namespace std;
string a,c,e,f;
int b,d,n=1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>e>>c>>d>>f;
	for(int i=1;i<=n;i++)
	{
	  if(a==c)
	  {
	    cout<<"1";
	    if(b==d)
	    {
	      cout<<"1";
	      if(e==f)
	        cout<<"11";
	      else
	        cout<<"00";
	    }
	    else
	      cout<<"000";
	  }
	  else
	  cout<<"0000";
	}
	return 0;
}
