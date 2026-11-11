#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,q=0,lzq[100000],ylh[100000],yq99=0;
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	{
		cin>>lzq[i];
		q+=lzq[i];
	}
	q=q%n;
	for(long long i=0;i<n;i++)
	{
		ylh[i]=q-lzq[i];
	}
	long long jj=0,JJ=0;
	for(long long i=0;i<n;i++)
	{
		jj++;
		JJ--;
		for(long long i=0;i<n;i++)
		{
			if(ylh[i]==jj||ylh[i]==JJ)
			{
				if(ylh[i]<0)
				{
					long long qq=0;
					qq-=ylh[i];
					ylh[i]+=qq*2;
				}
				m-=jj;
				if(m<0)
				{
					break;
				}
				else
				{
					ylh[i]-=jj;
				}
			}
		}
		
	}
	for(long long i=0;i<n;i++)
	{
		if(ylh[i]==0)
		{
			yq99++;
		}
	}
	cout<<yq99;
	return 0;
}
