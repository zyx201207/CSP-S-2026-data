#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char r[5],x[5];
	int a,b;
	for(int i=0;i<5;i++)
	{
		r[i]=getchar();
		if(r[i]==' ')
		r[i]=getchar();
    }
	for(int y=0;y<5;y++)
	{
		x[y]=getchar();
		if(x[y]==' ')
		x[y]=getchar(); 
    }   
    if(x[4]=='A'&&x[4]=='B'&&x[4]=='C')
    a=1;
    else
    a=0;
    if(r[4]=='A'&&r[4]=='B'&&r[4]=='C')
    b=1;
    else
    b=0;
    if(x[0]==r[0]&&x[1]==r[1])
    {
    	cout<<"1";
    	if(x[2]==r[2]&&x[3]==r[3])
    	{
    		cout<<"1";
    		if(a==b)
    		{
			cout<<"1";
			if(abs((int)(x[4])-(int)(r[4]))==1)
			cout<<"1";
			else
			cout<<"0";
			}
			else
			cout<<"00";
		}
		else
		cout<<"000";
	}
	else
	cout<<"0000" ;
	
	
	 
	 return 0;
}
