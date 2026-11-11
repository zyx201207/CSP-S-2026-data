#include <iostream>//80!
using namespace std;
int n,m,num[500005],a[300005],cnt=0,xb[300005],flag[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>num[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) a[j]=0;
		for(int j=1;j<=m;j++) xb[j]=0;
		cnt=0;
		for(int j=i;j<=n;j++)
		{
			if(xb[num[j]]==0)
			{
				cnt++;
				xb[num[j]]=cnt;
				a[cnt]=num[j];
			}
			else
			{
				for(int k=xb[num[j]]+1;k<=cnt;k++)
				{
					xb[a[k]]=0;
					a[k]=0;
				}
				cnt=xb[num[j]];
			}
		}
		for(int j=1;j<=m;j++)
			if(xb[j]!=0) flag[j]++;
		//cout<<'*';
		//for(int j=1;j<=m;j++) cout<<flag[j]<<' ';
		//cout<<'\n';			
	}
	for(int i=1;i<=m;i++) cout<<flag[i]<<' ';
	return 0;
}
