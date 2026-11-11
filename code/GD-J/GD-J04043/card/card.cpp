#include<bits/stdc++.h>
using namespace std;
//#define ll long long
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N];
bool isA=1;
int ansA[M];
int lst[N];
bool vis[N];
bool cnt[M];
int ans[M];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
			isA=0; 
	}
	for(int kase=1;kase<=n;kase++)
	{
		for(int i=0;i<=n;i++)
			vis[i]=0;
		for(int i=1;i<=m;i++)
			cnt[i]=0,lst[i]=0;
		for(int i=kase;i<=n;i++)
		{
			if(!lst[a[i]])
			{
				lst[a[i]]=i;
				continue;
			}
			if(vis[lst[a[i]]])
			{
				lst[a[i]]=i;
				continue;
			}
			for(int j=i-1;j>=max(kase,lst[a[i]]);j--)
				vis[j]=1;
			lst[a[i]]=i;
		}
		for(int i=kase;i<=n;i++)
		{
			if(cnt[a[i]])
				continue;
			if(!vis[i])
				cnt[a[i]]=1;
		}
		for(int i=1;i<=m;i++)
			ans[i]+=cnt[i];
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
/*
4 3
1 2 1 3
*/
