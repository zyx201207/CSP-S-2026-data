#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n,n1;
	string m,m1;
	cin>>n>>n1>>m>>m1;
	if(n==m)
	{
	    cout<<1;
		if(n1[0]==m1[0]&&n1[1]==m1[1])
		{
			cout<<1;
			if(n[2]=='A'&&m[2]=='B')
			{
				cout<<11;
			}
			else if(n[2]=='B'&&m[2]=='A')
		     	{
				    cout<<11;
		    	}
		    	else if(n[2]=='C'&&m[2]=='D'||n[2]=='D'&&m[2]=='C')
		        	{
				        cout<<11;
		            }
		            else if(n[2]=='C'&&m[2]=='F'||n[2]=='F'&&m[2]=='C')
		        	    {
				            cout<<10;
		                }
		                else if(n[2]=='F'&&m[2]=='D'||n[2]=='D'&&m[2]=='F')
		        	        {
				                cout<<11; 
		                    }
		                    else
							{
								cout<<00;
							}
		}
		else
		{
			cout<<000;
		}
	}
	else
	{
		cout<<0000;
	}
	
	return 0;
}
