#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	int a,b;
	string a1,b2;
	int ans[4]={0,0,0,0};
	cin>>a>>a1>>b>>b2;

	if(a==b)
	{
		ans[0]=1;
		if((int(a1[0])==int(b2[0]))&&(int(a1[1])==int(b2[1])))
		{
			ans[1]=1;
			if((a1[2]=='F'||a1[2]=='D')&&(b2[2]=='F'||b2[2]=='D'))
			{
				ans[2]=1;
				ans[3]=1;
			}
			if((a1[2]=='C'||a1[2]=='B'||a1[2]=='A')&&(b2[2]=='C'||b2[2]=='B'||b2[2]=='A'))
			{
				ans[2]=1;
				if((int(a1[2])+1)==int(b2[2])||(int(a1[2])-1)==int(b2[2])) ans[3]=1;
				if(a1[2]==b2[2])
				{
					for(int i=0;i<4;i++) ans[i]=0;
				}
			}
		}
	 } 
	for(int i=0;i<4;i++) cout<<ans[i];
	
	
 } 
