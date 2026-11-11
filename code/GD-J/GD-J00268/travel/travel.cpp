#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool k;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	char m=b[2],n=d[2];
	if(a==c)
	{
	    cout<<1;
		if(b[0]==d[0]&&b[1]==d[1])
		{
		    cout<<1;
			if((m-'C'<=0&&n-'C'<=0)||(m-'C'>0&&n-'C'>0))
	        {
	        	cout<<1;
    	    	k=true;
    	    }
    	    else
    	    {
    	    	cout<<0;
    	    	k=false;
    	    }
    	    if(k&&(abs(n-m)==1||min(n,m)-'D'>=0))cout<<1;
    	    else cout<<0;
		}
	    else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
