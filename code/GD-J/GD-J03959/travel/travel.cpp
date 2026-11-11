#include<bits/stdc++.h>
using namespace std;
int n,x,y,e,r,g,h;
string s1,s2,a1,a2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>s1>>a2>>s2;
	for (int i=0;i<2;i++)
	{
		x=x*10+(int)(a1[i]-'0');
		y=y*10+(int)(a2[i]-'0');
	}
	//cout<<x<<" "<<y<<" ";
	if (x!=y)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<"1";
		for (int i=0;i<2;i++)
	    {
		    e=e*10+(int)(s1[i]-'0');
		    r=r*10+(int)(s2[i]-'0');
	    }
	    //cout<<e<<" "<<r<<" ";
	    if (e!=r)
	    {
	    	cout<<"000";
	    	return 0;
		}
		else
		{
			cout<<"1";
			g=(s1[2]-'A');
			h=(s2[2]-'A');
			//cout<<g<<" "<<h<<" ";
			if ((g<=2&&h>2)||(g>2&&h<=2))
			{
				cout<<"00";
			}
			else
			{
				cout<<"1";
				if (abs(g-h)!=1)
				{
					cout<<"0";
				}
				else 
				{
					cout<<"1";
				}
			}
		}
	}
	return 0;
 } 
