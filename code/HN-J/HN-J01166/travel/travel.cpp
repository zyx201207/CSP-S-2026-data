#include<bits/stdc++.h>
using namespace std;
int a,b;
char c[5],d[5];
int main()
{
//freopen("travel.in","r",stdin);
//freopen("travel.out","w",stdout);
cin>>a;
for(int i=0;i<3;i++)
{
	cin>>c[i];
	c[i]=c[i]-'0';
}
cin>>b;
for(int i=0;i<3;i++)
{
	cin>>d[i];
	d[i]=d[i]-'0';
}
    if(a==b)
    {
    	if(c[1]==d[1]||c[2]==d[2])
    	{
		    if(c[3]>d[3])
		    {
		    	if(c[3]!='D')
		    	{
		    	if(c[3]-d[3]==1)
		    	{
		    	    cout<<"1111";
		        }
		        else
		        {
		        	cout<<"1110";
				}
	    	}else
		        {
		        	cout<<"1100";
				}
			}else
			{
				if(d[3]!='D')
				{
		    	if(d[3]-c[3]==1)
		    	{
		    	   cout<<"1111";
		        }
		        else
		        {
		        	cout<<"1110";
				}
		        }
		        else
		        {
		        	cout<<"1100";
				}
            }
	}
	else
	{
		cout<<"1000";
	}
}
else
{
	cout<<"0000"; 
}
    return 0;
}
