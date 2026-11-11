#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int pr,px;
	pr=(s1[0]+s1[1])-'0';
	px=(s2[0]+s2[1])-'0';
	if(c1==c2)
	{
		cout<<1;
		if(pr==px)
		{
		    cout<<1;
	        if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')
	        {
	            cout<<1;
				if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1)
				  cout<<1;
				else
				  cout<<0;	
			}
	        else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')
	        {
	            cout<<1;
				if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
				  cout<<1;
				else
				  cout<<0;	
			}
	        else
	          cout<<"00";
		}
		else
		  cout<<"000";
	}
	else
	  cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
