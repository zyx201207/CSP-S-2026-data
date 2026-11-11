//AH-J01662 LSJ Liu Shijie
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M],La[M],b[N],x[M];
bool f=1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	memset(La,-1,sizeof(La));
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i-1]>a[i])
		{
			f=0;
		}
		x[a[i]]++;
	}
	if(f)
	{
		for(int i=1;i<=m;i++)
		{
			x[i+1]+=x[i];
		}
		return 0;
	}
	for(int i=n;i>=1;i--)
	{
		b[i]=La[a[i]];
		La[a[i]]=i;
	}
	for(int i=1,k;i<=n;i++)
	{
		k=-1;
		for(int j=i;j<=n;j++)
		{
			while(b[j]!=-1)
			{
				j=b[j];
			}
			ans[a[j]]++;
		}
		if(k==-1)
		{
			k=i;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
// Trick||Treat!
