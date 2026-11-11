#include<bits/stdc++.h>
using namespace std;
int main(){
	int c1,c2,l,z;
	string s1,s2,a,b;
	char c,e;
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	l=s1.size();
	z=s2.size();
	a=s1[0]+s1[1];
	b=s2[0]+s2[1];
	c=s1[2];
	e=s2[2];
	
	if(c1==c2)
	{
		cout<<1;
		
		if(a==b)
		{
			cout<<1;
			
			if(a==b&&((c<='C'&&e<='C')||(c>'C'&&e>'C')))
			{
				cout<<1;
				
				if(abs(int(c)-int(e))==1)
            	cout<<1;
            	else
            	cout<<0;
			}
        	
	        else
	        {
	        	cout<<"00";
	        	return 0;
			}
		}
    	else
    	{
    		cout<<"000";
    		return 0;
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	
	return 0;
 } 
