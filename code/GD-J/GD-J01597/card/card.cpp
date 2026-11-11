#include<bits/stdc++.h>
using namespace std;
int ct[500005],nex[500005];
int T[500005],a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=n;i>=1;i--)
	{
		nex[i]=T[a[i]];
		T[a[i]]=i,ct[i]=1;
	}
	memset(T,0,sizeof(T));
	for(int i=1;i<=n;i++)
	{
		if(nex[i]) ct[nex[i]]+=ct[i];
		else T[a[i]]+=ct[i],ct[i+1]+=ct[i];
	}
	for(int i=1;i<=m;i++) printf("%d ",T[i]);
}
