#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,a,i,j,k,l,wei[200001][31],mi,ma,po[31]={1},he[31],ne[200001],shu[200001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=30;i++)po[i]=po[i-1]*2;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		mi=log(a)/log(2);
		ma=max(ma,mi);
		shu[i]=mi;
		while(a>0)
		{
			if(a>=po[mi])
			{
				wei[i][mi]=1;
				he[mi]++;
				a-=po[mi];
			}
			mi--;
		}
	}
	for(i=ma;i>=0;i--)
		if(he[i]>=k)
		{
			ans+=po[i];
			for(j=1;j<=n;j++)
				if(!ne[j]&&!wei[j][i])
				{
					ne[j]=1;
					for(l=shu[j];l>=0;l--)
						if(wei[j][l])
						{
							wei[j][l]=0;
							he[l]--;
						}
				}
		}
	cout<<ans;
	return 0;
}
