#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m;
int a[N];
bool flagA=1;
int ans[M];
int cfid;
int t[M];
int st[N],tp;
int tim;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=2;i--)
	{
		if(a[i]<a[i-1])
		{
			flagA=0;
			break;
		}
	}
	if(flagA)
	{
		for(int i=1;i<=n;i++)
		{
			ans[a[i]]=i;
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		tp=0;
		tim++;
		for(int j=i;j<=n;j++)
		{
			if(t[a[j]]==tim)
			{
				while(tp)
				{
					int v=st[tp--];
					t[v]=0;
					if(v==a[j]) break;
				}
			}
			t[a[j]]=tim;
			st[++tp]=a[j];
		}
		for(int j=1;j<=m;j++)
		{
			if(t[j]==tim) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

