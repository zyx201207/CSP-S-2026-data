#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int a[N],c[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		int b[N];
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++)
		{
			int f=0;
			for(int k=1,l=cnt;k<=l;k++)
			{
				if(b[k]==a[j]) f=1;
				if(f) b[k]=0,cnt--;
			}
			b[++cnt]=a[j];
			if(f) continue;
		}
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=cnt;k++)
			{
				if(b[k]==j)
				{
					c[j]++;
					break;
				}
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	return 0;
}
