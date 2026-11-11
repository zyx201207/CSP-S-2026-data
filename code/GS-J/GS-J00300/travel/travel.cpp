#include<bits/stdc++.h>
using namespace std;
int main()
{

	freeopen("travel.in","r",stdin);
	freeopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    bool s=0,x=0,y=0,z=0;
	if(a==c)
	{
		s=1;
	 if(b[1]==d[1]||b[2]==d[2])
     {
		x=1;
	    if(b[3]==c[3])
	   {
		 y=1;
	   }
	 }
	}         
	if(a==c)
	{
	if(b[1]==d[1]||b[2]==d[2])
	{
	   if(b[3]=="A"||d[3]=="B") {z=1;}if(d[3]=="A"||b[3]=="B") {z=1;}if(b[3]=="B"||d[3]=="C") {z=1;}if(b[3]=="C"||d[3]=="B") {z=1;}if(b[3]=="C"||d[3]=="D") {z=1;}if(b[3]=="D"||d[3]=="C") {z=1;}if(b[3]=="D"||d[3]=="F") {z=1;}if(b[3]=="F"||d[3]=="D") {z=1;}
	}
	 
	} 
	cout<<s<<x<<y<<z;
	return 0;
	
}
