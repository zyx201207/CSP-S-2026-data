#include<bits/stdc++.h>
using namespace std;
int n,m,ans,maxn;
int a[200005];
bool t[200005][31],f[200005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(maxn,a[i]);
		int tt=a[i];
		for(int j=30;j>=0;j--)
		{
			if(tt==0) break;
			int cnt=pow(2,j);
			if(tt>=cnt)
			{
				t[i][j]=1;
				tt-=cnt;
			}
		}
	}
	if(m==1)
	{
		cout<<maxn;
		return 0;
	}
	memset(f,true,sizeof f);
	bool flag=false;
	for(int j=30;j>=0;j--)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(!f[i])continue;
			if(t[i][j])cnt++;
		}
		if(cnt==0)continue;
		if(cnt<m&&flag) break;
		if(cnt>=m)
		{
			flag=true;
			for(int i=1;i<=n;i++)
			{
				if(!f[i])continue;
				if(!t[i][j]) f[i]=false;
			}
		}
		if(cnt==m)break;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]&&ans==0)
		{
			ans=a[i];
		}
		if(f[i])
		{
			ans&=a[i];
		}
	}
	cout<<ans;
	return 0;
}
