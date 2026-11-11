#include<bits/stdc++.h>
using namespace std;
struct node
{
	int c;
	int i;
};
const int N=5e5+5;
vector<int>v1;
vector<int>v2;
node c[N];
int a[N];
int cnt[N];
int n,m;
int maxx;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		v1.push_back(a[i]);
		maxx=max(maxx,a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		memset(c,0,sizeof c);
		for(int j=i;j<=n;j++)
		{
			if(c[v1[j]].c!=0)
			{
				for(int k=c[v1[j]].i+1;k<=n;k++)
				{
					v2[k]=0;
					cnt[v2[k]]--;
				}
			}
			else
			{
				cnt[v1[j]]++;
				c[v1[j]].c=1;
				c[v1[j]].i=j;
				v2.push_back(v1[j]);
			}
		}
	}
	for(int i=1;i<=maxx;i++)
	{
		cout<<cnt[i]<<" ";
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int T;
	T=1;
	while(T--)
	{
		solve();
	}
	return 0;
}
