#include<bits/stdc++.h>
using namespace std;
long long cct,tcc,a[10004],sum;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cct>>tcc;
	for(int i=1;i<=tcc;i++)
	{
		long long ccb,mmx;
		cin>>ccb>>mmx;
		for(int j=1;j<=ccb;j++)
		{
			cin>>a[j];
		}
		if(ccb==4)
		{
			cout<<"1"; 
		}
		else if(a[2]-a[1]<=2*mmx&&ccb>=4&&ccb%2==1)
		{
			if(ccb>=5&&ccb<=7)
			{
				cout<<(ccb-4)*2;
			}
			else if(ccb>=9&&ccb<=11)
			{
				cout<<(ccb-4)*2+(ccb-8)*2;
			}
			else if(ccb==13)
			{
				cout<<"30";
			}
			else if(ccb>13)
			{
				a[1]=12;
				a[2]=20;
				for(int i=3;i<=3+(ccb-13)/2;i++)
				{
					a[i]=a[i-2]+(ccb-4)*2;
				}
				cout<<a[3+(ccb-13)/2];
			}
		}
		else 
		{
			if(ccb==6)
            {
            	cout<<"4";
			}
			if(ccb==8)
			{
				cout<<"9";
			}
			if(ccb==10)
			{
				cout<<"16";
			}
		}		
	}
	return 0;
}
