#include<bits/stdc++.h>
using namespace std;

int ux;

string rc,rz,xc,xz;
bool ans[6];

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rz>>xc>>xz;
	if(rc==xc)
	{
		ans[1]=1;
		if(rz[0]==xz[0]&&rz[1]==xz[1])
		{
			ans[2]=1;
			if(rz[2]<='C'&&xz[2]<='C'||rz[2]>='D'&&xz[2]>='D')
			{
				ans[3]=1;
				if(abs((int)(rz[2]-xz[2]))==1)
				{
					ans[4]=1;
				}
			}
		}
	}
	for(int i=1;i<=4;i++)
	{
		cout<<ans[i];
	}
	return 0;
} 
