#include<bits/stdc++.h>
using namespace std;
long long a,b,c,as[2000001],ls[2000001],rs[2000001],l,r,out,dps[2000001][3],dpe[2000001][3];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a>>a;
	for(int i=1;i<=a;i++)
	{
		cin>>b>>c;l=r=1;out=0;
		for(int j=1;j<=b;j++)
		{
			cin>>as[j];
			dps[j][0]=dpe[j][0]=dps[j][1]=dpe[j][1]=dps[j][2]=dpe[j][2]=0;
		}
		for(int j=1;j<=b;j++)
		{
			for(;as[l]<as[j]-c;l++);
			for(;r<b&&as[r+1]<=as[j]+c;r++);
			ls[j]=l;rs[j]=r;
			if(ls[j]!=j)dps[ls[j]][0]++,dps[ls[j]][2]++;
			if(rs[j]!=j)dpe[rs[j]][0]++,dpe[rs[j]][2]++;
		}
		for(int j=1;j<=b;j++)
		{
			if(ls[j]!=j&&rs[ls[j]]==j)dpe[j][1]+=dpe[ls[j]][1]+dpe[ls[j]][0]+1,dpe[j][0]--;
		}
		for(int j=b;j;j--)
		{
			if(rs[j]!=j&&ls[rs[j]]==j)dps[j][1]+=dps[rs[j]][1]+dps[rs[j]][0]+1,dps[j][0]--;
		}
		for(int j=1;j<b;j++)
		{
			if(ls[j+1]<j&&rs[j]>j+1)
			{
				if(ls[j]==ls[j+1]&&rs[ls[j+1]]==j+1)
				{
					if(rs[j]==rs[j+1]&&ls[rs[j]]==j)
					{
						out+=(dps[rs[j]][1]+dps[rs[j]][0])*(dpe[ls[j+1]][1]+dpe[ls[j+1]][0]);
					}
					out+=dps[j][2]*(dpe[ls[j+1]][1]+dpe[ls[j+1]][0]);
				}
				if(rs[j]==rs[j+1]&&ls[rs[j]]==j)
				{
					out+=(dps[rs[j]][1]+dps[rs[j]][0])*dpe[j+1][2];
				}
				out+=dps[j][2]*dpe[j+1][2];
			}
		}
		cout<<out<<'\n';
	}
	return 0;
}
