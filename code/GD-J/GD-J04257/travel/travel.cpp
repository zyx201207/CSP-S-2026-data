#include <bits/stdc++.h>
using namespace std;

int a[5];
int b[5];

int main()
{
	freopen("trave.in","r",stdin) ;
	freopen("trave.out","w",stdout) ;
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<3;i++)
	{
		a[i]=s1[i];
		b[i]=s2[i];
	}
	if(c1!=c2)
	    cout<<"0000";
	else if(c1==c2)
	{
		cout<<'1';
			if(a[0]==b[0]&&a[1]==b[1])
			{
				cout<<'1';
		        if(a[2]>='A'&&a[2]<='C'&&b[2]>='A'&&b[2]<='C')
				{
			    	cout<<'1';	
			    	if(a[2]=='B'||b[2]=='B')
					{
			    		cout<<'0';
					}
			    	else cout<<'1';
		    	}
	            else if(a[2]>='D'&&a[2]<='F'&&b[2]>='D'&&b[2]<='F') 
				{
	            	cout<<'1'<<'1';
				}
	            else
	                cout<<'0'<<'0';
			}
	        else
	            cout<<'0'<<'0'<<'0';
	}
	
	return 0;
}
