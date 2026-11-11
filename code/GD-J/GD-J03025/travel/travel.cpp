#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,b1;
	char a2[5],b2[5];
	cin>>a1>>a2>>b1>>b2;
	int a21=a2[0]+a2[1];
	char a22=a2[2];
	int b21=b2[0]+b2[1];
	char b22=b2[2];
	int sum1=0,sum2=0,sum3=0,sum4=0;
	if(a1!=b1)
	{
		cout<<"0000";
		return 0;
	}
	if(a1==b1)
	{
		sum1=1;
		if(a21==b21)
		{
			sum2=1;
			if(a22-b22<=5||b22-a22<=5)
			{
				if(!((b22-a22==1||a22-b22==1)&&((a22=='C'&&b22=='D')||(a22=='D'&&b22=='C'))))
				{
					sum3=1;
					if(b22-a22==1||a22-b22==1)
					{
						sum4=1;
					}
				}
				if((a22=='D'&&b22=='F')||(a22=='F'&&b22=='D'))
				{
					sum3=1;
					if(b22-a22==1||a22-b22==1)
					{
						sum4=1;
					}
				}
			}
		}
	}
	cout<<sum1<<sum2<<sum3<<sum4;
	return 0;
}
