//card.cpp
#include<iostream>
using namespace std;

int main()
{
    freopen("card","r",stdin);
    freopen("card","w",stdout);
    int m,k;
    cin>>m>>k;
    for(int n=1;n<=m;n++)
    {
		for(int i=i-1;i<=n;i++)
		{
			if(k==0)
			{
				i+=1;
		    }
		    else
		    {
				i+=0;
		    }
		    cout<<i;
	    }
    }
    return 0;
 }
