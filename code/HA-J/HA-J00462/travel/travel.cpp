#include<bits/stdc++.h>
using namespace std;

int main()
{	
	
 	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	

	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	bool chexiang=(c1==c2);
	bool pai=(s1[0]==s2[0]  &&  s1[1]==s2[1]);
	bool ce=0;
	bool next=0;
	
	int TorF=3;
	if(s1[2]=='A' ||  s1[2]=='B' ||  s1[2]=='C' ) TorF=0;
	if(s1[2]=='D' ||  s1[2]=='F'  ) TorF=1;
	
	if((s2[2]=='A' ||  s2[2]=='B' ||  s2[2]=='C') && TorF==0) 
	{
		ce=1;
	}
	else if((s2[2]=='D' ||  s2[2]=='F') && TorF==1) 
	{
		ce=1;
	}
	else
	{
		ce=0;
	}
	

	if(s1[2]=='C' && s1[2]=='D') 
	{next=0;
	}	
	else if(s1[2]=='D' && s1[2]=='C') 
	{next=0;
	}
	else if(s1[2]-s2[2]==1 || s2[2]-s1[2]==1)
	{next=1;
	}
	else if(s1[2]=='D' && s1[2]=='F' || s1[2]=='F' && s1[2]=='D' )
	{next=1;
	}
	else
	{next=0;
	}
	
	
	if(chexiang==0)
	{cout<<"0000";
	}
	else if(pai==0)
	{cout<<"1000";
	}
	else if(ce==0)
	{cout<<"1100";
	}
	else if(next==0)
	{cout<<"1110";
	}
    else
    {cout<<"1111";
    }

	return 0;
} 
