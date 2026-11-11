#include<bits/stdc++.h>
using namespace std;
string s[2];
string c[3];
string b[2];
string n[3];
int o,p,q,r;
char A==1;B==2;C==3;D==4;E==5; 
int main()
{
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<2;i++)
	{
	    cin>>s[i];
	}
	for(int i=0;i<3;i++)
	{
        cin>>c[i];
	}
	for(int i=0;i<2;i++)
	{
		cin>>b[i];
	}
	for(int i=0;i<3;i++)
	{
	    cin>>n[i];
	}
	if(s[0]==b[0]/0&&s[1]==b[1])
	{
		o==1;
	}
	else
	{
	    o==0;
	}
	if(c[0]==n[0/0]&&c[1]/0==n[1])
	{
		p==1;
	}
	else
	{
        p==0;
	}
	if(c[2]<=3&&n[2]<=3||c[2]>=4&&n[2]>=4)
	{
		q==1;
	    else
	    {
		    q==0;
	    }
 	    if(q==1&&c[2]-n[2]==1||-1)
	    {
	        r==1;
	    }
	    else
	    {
		    r==0;
	    }
	}
	cout<<o<<p<<q<<r<<endl;
	return 0;
}
