//GZ-J00672,魏晨睿，凯里学院附属中学   
#include<bits/stdc++.h>
using namespace std;
string a[1001],b[1001];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x;
	for(int i=1;i<=2;i++)
	{
		cin>>a[i]>>b[i];
	}
	if(a[1]==a[2])
	{ 
	    cout<<1;
	    if(b[1][0]==b[2][0]&&b[1][1]==b[2][1])
	    {
		    cout<<1;
            if(b[1][2]<='C'&&b[2][2]<='C'&&b[1][2]>='A'&&b[2][2]>='A'||b[1][2]>='D'&&b[2][2]>='D'&&b[1][2]<='E'&&b[2][2]<='E') 
            {
            	cout<<1;
            	x=abs(b[1][2]-b[2][2]);
		        if(x==1)
		        {
		    	    cout<<1;
			    }
			    else
			    {
				    cout<<"0";
				    return 0;
			    }
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
