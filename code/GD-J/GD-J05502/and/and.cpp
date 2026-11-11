#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m,nx[200005],pr[200005],ma,gs[200005],mm,now,ans=(1<<30)-1;
bool b[200005][32];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n+1;i++) nx[i]=i+1,pr[i]=i-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		int t=a[i],tot=0;
		while(t!=0)
		{
			tot++;
			b[i][tot]=t&1;
			if(b[i][tot]) gs[tot]++;
			t>>=1;
		}
		ma=max(ma,tot);
	}
	for(int i=ma;i>=1;i--)
	{
		mm=0;
		for(int j=nx[0];j<=n;j=nx[j])
		{
			if(b[j][i])
			{
				mm++;
			}
		}
		if(mm>=m)
		for(int j=nx[0];j<=n;j=nx[j])
		{
			if(!b[j][i]) nx[pr[j]]=nx[j],pr[nx[j]]=pr[j];
		}
	}
	int ttt=0;
	for(int i=nx[0];i<=n&&ttt<=m;ttt++,i=nx[i])
	{
		ans&=a[i];
	}
	printf("%d",ans);
	return 0;
}
