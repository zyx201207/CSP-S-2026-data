#include <bits/stdc++.h>
using namespace std;
const int N=500005,M=300005;
int n,m,a[N],ans[M],now[N],len=0,curr=1,jushi=1; 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	while(true)
	{
		if(jushi>n)
		{
			break;
		}
		bool is_x=0;
		int idx=0;
		for(int i=1;i<=len;i++)
		{
			if(now[i]==a[curr])
			{
				is_x=1;
				idx=i;
				break;
			}
		}
		if(!is_x) now[++len]=a[curr];
		else
		{
			for(int i=idx+1;i<=len;i++)
			{
				now[i]=0;
			}
			if(idx==1)
			{
				len-=idx;
			}
			else len=len-idx+1;
		}
		if(curr==n)
		{
			for(int i=1;i<=len;i++)
			{
				for(int j=1;j<=m;j++)
				{
					if(now[i]==j) ans[j]++;
				}
			}
			jushi++;
			curr=jushi;
			memset(now,0,sizeof(now));
			len=0;
			continue;
		}
		curr++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
