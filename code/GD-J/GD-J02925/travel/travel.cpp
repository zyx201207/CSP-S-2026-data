#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travelin","r","stdin");
	freopen("travelout","w","stdout");
    string a,b;
	for(int i=1;i<=5;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=5;i++)
	{
		cin>>b[i];
	}

	if(a[1]==b[1]&&a[2]==b[2]&&a[1]!='1'&&a[2]!='16')
	{
		cout<<"1"<<endl;
		if(a[4]==b[4]&&a[3]==b[3])
	    {
		    cout<<"1"<<endl;
		    if((a[5]<='C'&&b[5]>='D')||(a[5]>='D'&&b[5]<='C'))
	        {
		       cout<<"0"<<endl<<"0"<<endl;
	        }
	        else
	        {
		       cout<<"1"<<endl;
		       if((a[5]-'0')-(b[5]-'0')==1||(b[5]-'0')-(a[5]-'0')==1)
		       {
	            
		           cout<<"1"<<endl;
	            }
	            else
	            {
		           cout<<"0"<<endl;
	            }
	        }
	    }  
	    else
	    {
		    cout<<"0"<<endl<<"0"<<endl<<"0"<<endl;
        }
	}
	else
	{
		cout<<"0"<<endl<<"0"<<endl<<"0"<<endl<<"0"<<endl;
	} 
} 
