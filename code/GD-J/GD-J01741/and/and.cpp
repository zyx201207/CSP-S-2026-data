#include<bits/stdc++.h>
using namespace std;
int n,m,b[200003],d,ans,ed[34],w;
int o[200003],cnt;
bool cmp(int a,int c)
{
	return a>c;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	ed[0]=1;
	for(int i=1;i<=30;i++)ed[i]=ed[i-1]*2;
	w=n;
	sort(b+1,b+n+1,cmp);
	for(int i=30;i>=0;i--)
	{
		cnt=0;
		for(int j=1;j<=w;j++)
		{
			if(b[j]/ed[i]%2==1)cnt++;
			b[j]%=ed[i];
		}
		if(cnt>=m)
		{
			ans+=ed[i];
			w=cnt;
		}
		sort(b+1,b+cnt+1,cmp);
	}
	cout<<ans;
	return 0;
}
