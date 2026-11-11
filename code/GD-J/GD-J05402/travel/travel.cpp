#include<bits/stdc++.h>
using namespace std;
string _rcs,_xcs,_rz,_xz;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>_rcs>>_rz>>_xcs>>_xz;
	int sum=1;
	for(int i=0;i<=1;i++)
	{
		if(_rcs[i]!=_xcs[i]) sum=0;
	}
	if(sum)
	{
		cout<<1;
		for(int i=0;i<=1;i++)
		{
			if(_rz[i]!=_xz[i]) sum=0;
		}
		if(sum)
		{
			cout<<1;
			int rst=int(_rz[2]-'A'+1);
			int xst=int(_xz[2]-'A'+1);
			if((rst<=3&&xst<=3)||(rst>=4&&xst>=4))
			{
				cout<<1;
				if(max(rst,xst)-min(rst,xst)==1)
				{
					if(!(max(rst,xst)==4&&min(rst,xst)==3))
					{
						cout<<1;
					} else cout<<0;
				} else cout<<0;
			} else cout<<0<<0;
			
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
} 
