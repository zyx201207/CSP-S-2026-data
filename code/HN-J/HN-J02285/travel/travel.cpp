#include<bits/stdc++.h>
using namespace std;
int main()
{
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   char a,b;
   int zp[2];
   int nb[2];
   for(int i=0;i<2;i++)
   cin>>zp[i];
   cin>>a;
   for(int j=0;j<2;j++)
   cin>>nb[j];
   cin>>b;
   int a1=(int)a;
   int b1=(int)b;
  if(zp[0]!=nb[0])
  cout<<"0000";
  else{
    if(zp[1]!=nb[1]&&a1!=b1)
  	cout<<"1000";
  	 else if(a=='C'&&b=='D')
	cout<<"1100";
	else if(((a1==b1+1)||(a1==b1-1))&&zp[1]==nb[1])
	cout<<"1111";
	else cout<<"1110";
  }
}
	

