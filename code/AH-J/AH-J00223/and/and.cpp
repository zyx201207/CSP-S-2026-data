#include<bits/stdc++.h>
using namespace std;
long long a[200005],ans;
int bi[200005][50],flag[200005],ans_bi[50],n,m;
void solve()
{
	for(int i=1;i<=n;i++)
	{
		flag[i]=1;
	}
	for(int i=30;i>=1;i--)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			cnt+=flag[j]&bi[j][i];
		}
		if(cnt<m)
		{
			ans_bi[i]=0;
		}
		else
		{
			ans_bi[i]=1;
			for(int j=1;j<=n;j++)
			{
				flag[j]&=bi[j][i];
			}
		}
	}
}	
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(NULL);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<=30;j++)
		{
			bi[i][j]=a[i]&1;
			a[i]>>=1;
		}
	}
	solve();
	for(int i=30;i>=1;i--)
	{
		ans=ans*2+ans_bi[i];
	}
	cout<<ans;
	return 0;
}
