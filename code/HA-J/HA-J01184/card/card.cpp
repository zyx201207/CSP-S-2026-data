#include<bits/stdc++.h>;
using namespace std;

int main() 
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long a,b;
	cin>>a>>b;
	long long c[a+5],tt[a+5],t[a],cnt=a,l=1;
	for (int i=1;i<=a;i++)
	{
		cin>>c[i];
	}
	while(cnt>=1)
	{
		for(int i=l;i<=cnt;i++)
		{
			long long ls=c[i];
			tt[ls]++;
			l++;
			for (int i=1;i<=cnt;i++)
			{
				if(tt[i]>1)
				{
					cnt-=l;
					for (int i=1;i<=cnt;i++)
					{
						ls=c[i];
						t[ls]++;
					}
				}
			}
			
		}
	}
	for(int i=1;i<=b;i++)
	{
		cout<<t[i]<<" ";

	}
	return 0;
}
