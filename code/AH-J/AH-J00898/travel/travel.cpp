#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
    char D,F,A,B,C;
	cin>>a>>b>>c>>d;

	if(a==c)
	{
		cout<<"1";
		if(b[0,1]==d[0,1])
		{
			cout<<"1";
			if(b[2]==D||b[2]==F)
			{
				if(d[2]==D||d[2]==F)
				{
					cout<<"11";
				}else cout<<"00";
			}else 
			 if((b[2]==A||b[2]==B)||b[2]==C)
			 {
			 	    if((d[2]==A||d[2]==B)||d[2]==C)
					 {
					 	cout<<"1";
					 	if(b[2]==A)
					 {
					 	if(d[2]==B)
						 {
					 		cout<<"1";
							
						 }else cout<<"0";
						 
					 }else
						 if(b[2]==B)
						 {
						 	cout<<"1";
						 	
						 }else 
						 	if(d[2]==B)
							 {
							 	cout<<"1";
							 	
							 }else cout<<"0";
					
					 }else cout<<"00";
		
				}else cout<<"00";
		    
		}else cout<<"000";
		
	}else cout<<"0000";
	return 0;
}
