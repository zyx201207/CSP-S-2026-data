#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],c[300005],ans[300005],ca[300005];
main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(c,0,sizeof(c));
		memset(ca,0,sizeof(ca));
		int tmp=0;
		for(int j=i;j<=n;j++)
		{
			if(c[a[j]]!=0) 
			{
				for(int k=c[a[j]];k<=tmp;k++) c[ca[k]]=0,ca[k]=0,tmp--;
			}
			c[a[j]]=++tmp,ca[tmp]=a[j];
		}
		for(int j=1;j<=m;j++)
		{
			if(c[j]!=0) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
