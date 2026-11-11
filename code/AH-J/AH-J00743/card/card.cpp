#include <bits/stdc++.h>
using namespace std;
int a[500010],b[500010],xb[300010],ans[300010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
		int t=0;
		for(int j=i;j<=n;j++)
		{
			int f=-1;
			for(int k=1;k<=t;k++)
			{
				if(b[k]==a[j])
				{
					f=k;
					break;
				}
			}
			if(f==-1) b[++t]=a[j];
			else
			{
				for(int k=f;k<=t;k++) b[k]=0;
				t=f;
				b[f]=a[j];
			}
		}
		for(int j=1;j<=t;j++) ans[b[j]]++;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}
