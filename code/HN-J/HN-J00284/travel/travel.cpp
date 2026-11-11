#include<bits/stdc++.h>
using namespace std;
string rt,rz,xt,xz;//³µÏá + ×ùÎ» + ÅÅÊý 
//int ;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rt>>rz>>xt>>xz;
	if(rt[0] == xt[0] && rt[1] == xt[1])
	{
		cout<<1;
		
		if(rz[0] == xz[0] && rz[1] == xz[1])
		{
			cout<<1;
			
			if(rz[2] <= 'C' && xz[2] <= 'C' || rz[2] > 'C' && xz[2] > 'C')
			{
				cout<<1;
				
				if(abs(rz[2] - xz[2]) == 1)
					cout<<1;
				else
					cout<<0;
//				cout<<" "<<abs(rz[2] - xz[2])<<rz[2]<<xz[2];
			}
			else
				cout<<"00";
				
		}
		else
			cout<<"000";
	}	
	else
		cout<<"0000";






	return 0;
}

