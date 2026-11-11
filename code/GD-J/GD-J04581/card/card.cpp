#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
bool p[N];
int w[N];
int ans[N];
int sum;
int cnt[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	int i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			if(p[a[j]]==true)
			{
				ans[w[a[j]]]+=1;
				ans[j]-=1;
				for(k=w[a[j]];k<j;k++)
				{
					p[a[k]]=false;
				}
				p[a[j]]=true;
			}
			else
			{
				w[a[j]]=j;
				p[a[j]]=true;
			}
		}
		for(j=i;j<=n;j++)
		{
			sum+=ans[j];
			if(sum==0)
			{
				cnt[a[j]]++;
			}
		}
		memset(p,false,sizeof(p));
		memset(ans,0,sizeof(ans));
		memset(w,0,sizeof(w));
	}
	for(i=1;i<=m;i++)
	{
		cout<<cnt[i]<<' ';
	}
	return 0;
 } 
