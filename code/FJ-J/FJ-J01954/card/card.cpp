#include<bits/stdc++.h>
#define int long long
#define TNF 0x3f3f3f3f3f3f3f3f
#define endl '\n' 
using namespace std;
using pii=pair<int,int>;
int n,m;
int a[500010];
int cnt[500010];
int ls[500010];
void d()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ls[a[i]]=i;
	}
	cnt[a[n]]=n;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[n])continue;
		for(int j=ls[a[i]];j<=n;j++)
		{
			if(j!=ls[a[j]])
			{
				j=ls[a[j]];
				continue; 
			}
			if(a[j]==a[n])continue;
			cnt[a[j]]++;
		}
	}
	//cnt[a[n-1]]+=2;
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	//cin>>t; 
	while(t--)d();
}
/*10 3
3 1 2 1 3 2 3 1 2 1*/
