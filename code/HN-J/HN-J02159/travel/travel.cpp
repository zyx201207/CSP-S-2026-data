#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int k=0,z,d=0;
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3)
	  cout<<"1";
	else
	{
	  cout<<"0000";
	  k=1;
 	}
 	if(k==0)
	  if(c2[0]==c4[0]&&c2[1]==c4[1])
	    cout<<"1";
	  else
	  {
	  	cout<<"000";
	  	k=1;
	  }
	if(k==0)
	{
	  if(c2[2]-0>=65&&c2[2]-0<=67&&c4[2]-0>=65&&c4[2]-0<=67)
	    d=1;
	  if(c2[2]-0>=68&&c2[2]-0<=69&&c4[2]-0>=68&&c4[2]-0<=69)
	    d=1;
	  if(d==1)
	    cout<<"1";
	  else
	  {
	  	cout<<"00";
	  	k=1;
	  }
	}
	if(k==0)
	  if(c2[2]-c4[2]==1||c2[2]-c4[2]==-1)
	    cout<<"1";
	  else
	    cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
