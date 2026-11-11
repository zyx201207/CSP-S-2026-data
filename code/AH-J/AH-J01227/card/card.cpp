#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],l[500005],b[500005],s;
bool f[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>l[i];
	while(1)
	{
		s++;
		if(s>n)
			break;
		int id=s-1,t=n;
		for(int i=s;i<=t;i++)
		{
			id++;
			int cnt=0;
			for(int j=s;j<i;j++)
			{
				if(a[j]==l[id])
				{
					for(int k=j;k<i;k++)
					{
						cnt++;
						a[k]=0;
					}
					break;
				}
			}
			i-=cnt;
			t-=cnt;
			a[i]=l[id];
		}
		memset(f,0,sizeof(f));
		for(int j=s;j<=t;j++)
		{
			if(f[a[j]]==0)
			{
				f[a[j]]=1;
				b[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
		cout<<b[i]<<' ';
	return 0;
}
