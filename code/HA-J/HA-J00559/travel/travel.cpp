#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string g1="",g2="";
	for(int i=0;i<2;i++)
	{
		g1+=s1[i];
		g2+=s2[i];
	}
	if(c1==c2) 
	{
		cout<<"1";
		if(g1==g2)
		{
			cout<<"1";
		    if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))
		    {
		    	cout<<"1";
		    	if(abs((int)(s1[2])-(int)(s2[2]))==1)
		    	{
		    		cout<<"1";
		    	}
		    	else cout<<"0";
		    }
		    else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
