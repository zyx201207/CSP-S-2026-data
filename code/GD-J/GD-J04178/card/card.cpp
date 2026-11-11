#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
const int N=5e5+5;
const int M=3e5+5;
int a[N],last[M],p[N],cnt,ans[N]; 
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		memset(last,-1,sizeof(last));
		cnt=0;
		memset(p,0,sizeof(p));
		for(int j=i;j<=n;j++)
		{
//			for(int k=1;k<=cnt;k++) cout<<p[k]<<" ";
//			cout<<endl;
			if(last[a[j]]==-1)
			{
				last[a[j]]=++cnt;
				p[cnt]=a[j];
			}
			else
			{
				int l=last[a[j]];
				for(int k=l;k<=cnt;k++) last[p[k]]=-1,p[k]=0;
				last[a[j]]=l;
				cnt=l;
				p[cnt]=a[j];
			}
		}
		for(int j=1;j<=m;j++) ans[j]=ans[j]+(last[j]!=-1);
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
