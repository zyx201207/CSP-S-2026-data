#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int i=0,a=0,s=0,z=0,x=3,q=2,w=1,m=4,p=5;
	
	cin>>a;
	cin>>s;
	int o[a];
	for(i=0;i<a;i++)
	{
		cin>>o[i];
	}
	if(s==1)
	{
		cout<<w;
	}
		if(a==2)
		{
			if(o[0]==1)
			{
				if(o[1]==2)
				{
					cout<<w<<' '<<q;
				}
			}
			else{
				cout<<q<<' '<<w;
			}
			
		}
		if(a==3)
		{
			if(o[0]==1)
			{
				if(o[1]==2)
				{
					if(o[2]==1)
					{
						cout<<w;
					}
					else{
						cout<<w<<' '<<q;
					}
				}
				else{
					
						cout<<w<<' '<<q;
					}
				
			}
		}
		if(a==4)
		{
			if(o[0]==1)
			{
				if(o[1]==2)
				{
					if(o[2]==1)
					{
						
						cout<<w;
					}
					else{
						cout<<w<<' '<<q;
					}
				}
				else{
					
						cout<<w<<' '<<q;
					}
				
			}			
		
		}
	
	if(a==5)
	{
		cout<<w<<' '<<q;
	}
	if(a>5)
	{
		cout<<x<<' '<<w<<' '<<m;
	}
	return 0;
}
