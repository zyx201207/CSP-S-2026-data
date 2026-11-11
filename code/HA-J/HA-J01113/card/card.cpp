#include <bits/stdc++.h>
using namespace std;
int n,m,a[50005],b[30005],c[30005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","W",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			cnt++;
			b[cnt]=a[j];
			for(int k=1;k<cnt;k++)
			{
				if(b[k]==a[j])
				{
					int ppp=cnt;
					for(int p=k+1;k<=ppp;p++) b[p]=0,cnt--;
					break;
				}
			}
		}
		for(int j=1;j<=cnt;j++) c[b[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	return 0;
}
