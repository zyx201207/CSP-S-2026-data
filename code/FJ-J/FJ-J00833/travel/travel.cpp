#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cnt=0,cnt2=0;
	string x1,z1,x2,z2;
	cin>>x1>>z1>>x2>>z2;
	bool ok1=0,ok2=0,ok3=0;
	if(x1==x2)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<z1.size()-1;i++)
	{
		cnt=cnt+z1[i];
		cnt2=cnt2+z2[i];
	}
	for(int i=0;i<z1.size();i++)
	{
		if(cnt==cnt2)
		{
			ok1=1;
		}
		if((z1[i]>68&&z2[i]>=68&&i==2&&ok1==1)||(z1[i]>=68&&z2[i]>68&&i==2&&ok1==1))
		{
			ok2=1;
		}
		else if((z2[i]<67&&z1[i]<=67&&i==2&&ok1==1)||(z2[i]<=67&&z1[i]<67&&i==2&&ok1==1))
		{
			ok2=1;
		}
		if(ok2==1)
		{
			if(z2[i]-z1[i]==1)
			{
				ok3=1;
			}
		}
	}
	cout<<ok1<<ok2<<ok3;
	return 0;
}
