#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int q=0,w=0,e=0,r=0;
	string cn,cnq,cnw,cne;
	cin>>cn>>cnq>>cnw>>cne;
	if(cn[0]!=cnw[0]||cn[1]!=cnw[1])
	{
		cout<<"0000";
		return 0;
	}
	else{
		q=1;
		if(cnq[0]==cne[0]&&cnq[1]==cne[1])
		{
			w=1;
			if((cnq[2]=='A'||cnq[2]=='B'||cnq[2]=='C')&&(cne[2]=='A'||cne[2]=='B'||cne[2]=='C'))
			{
				e=1;
				if(cnq[2]=='B'||cne[2]=='B')
				{
					r=1;
				}
			}
			if((cnq[2]=='F'||cne[2]=='F')&&(cnq[2]=='D'||cne[2]=='D')){
				e=1;
				r=1;
			}
		}
		cout<<q<<w<<e<<r;
	}
	return 0;
}
