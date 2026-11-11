#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],num[M],cnt,sum[M];
int b[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int j=1;j<=n;j++)
	{
		cnt=0;
		memset(num,0,sizeof num);
		for(int i=j;i<=n;i++)
		{
			cnt++;
			if(!num[a[i]])
			{
				num[a[i]]=cnt;
				b[cnt]=a[i];
			}
			else cnt=num[a[i]];
		}
		for(int i=1;i<=cnt;i++)
			sum[b[i]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<sum[i]<<' ';
	return 0;
}
