#include<bits/stdc++.h> 
using namespace std;
char c1[20],s1[10],c2[20],s2[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i = 1;i <=18;i++)
	{
		for(int j = 1;j <= 5;j++) 
		{
			
	     	if(c1[i] == c2[i] && s1[j] == s2[j+1])
	    	{
	    	    cout << "1";
		    }
		    else
		    {
		    	cout << "0";
			}
    	}
	}
	return 0;
}
