#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],l,r,ans[300005],biao[500005];
bool B[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		l=n;
		r=i;
		for(int j=i;j<=n;j++)
		{
			if((biao[a[j]]>=r||biao[a[j]]<=l)&&biao[a[j]]!=0) r=max(r,j),l=min(l,biao[a[j]]);
			biao[a[j]]=j;
			B[a[j]]=0;
		}
		l=min(l,r);
		//cout<<endl<<l<<" "<<r<<endl;
		for(int j=i;j<=n;j++)
		{
		   if((j>=r||j<=l)&&B[a[j]]==0) ans[a[j]]++,B[a[j]]=1;
		   biao[a[j]]=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
