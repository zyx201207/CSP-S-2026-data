#include <iostream>
#include <cstring>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N],q[N];
int lst[M],cnt,ans[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		memset(lst,0,sizeof lst);
		for(int j=i;j<=n;j++)
		{
			if(lst[a[j]])
			{
				for(int k=lst[a[j]]+1;k<=cnt;k++)
				{
					lst[q[k]]=0;
				}
				cnt=lst[a[j]];
			}
			else
			{
				cnt++;
				q[cnt]=a[j];
				lst[a[j]]=cnt;
			}
		}
		for(int j=1;j<=cnt;j++)
		{
			ans[q[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
