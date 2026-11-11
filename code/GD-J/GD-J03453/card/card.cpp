#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],d;
bool fA=true,fC=true,ff[300005],f[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]<a[i-1]) fA=false;
		if(a[i]!=a[i-1]&&!ff[a[i]]) ff[a[i]]=true;
		else if(a[i]!=a[i-1]&&ff[a[i]]) fC=false;
	}
	if(fA)
	{
		for(int i=2;i<=n;i++)
			if(a[i]!=a[i-1]) printf("%d ",i-1);
		cout<<n;
		return 0;
	}
	if(fC)
	{
		for(int i=2;i<=n;i++)
			if(a[i]!=a[i-1]) b[a[i-1]]=i-1;
		b[a[n]]=n;
		for(int i=1;i<=m;i++) printf("%d ",b[i]);
		return 0;
	}
	for(int i=1;i<=m;i++) cout<<1<<" ";
	return 0;
}
