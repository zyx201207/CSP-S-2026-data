#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5,maxm=3e5;
int n,m;
bool in[maxn];
int a[maxn],lst[maxm],cnt[maxn],ans[maxm];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int t=1;t<=n;++t)
	{
		memset(in,0,sizeof(in));
		memset(lst,0,sizeof(lst));
		memset(cnt,0,sizeof(cnt));
		for(int i=t;i<=n;++i)
		{
			int p=a[i];
			++cnt[p];
			if(!lst[p]) lst[p]=i;
			else
			{
				for(int j=lst[p];j<i;++j)
				{
					if(in[j]) continue;
					if(j>lst[p]) lst[a[j]]=0;
					in[j]=1,--cnt[a[j]];
					for(int k=lst[p]-1;k>=1;--k) 
					{
						if(a[j]==a[k]&&in[k])
						{
							lst[a[j]]=k;
							break;
						}
					}
				}
				lst[p]=i;
			}
		}
		for(int i=1;i<=m;++i) if(cnt[i]>0) ++ans[i];
	}
	for(int i=1;i<=m;++i) cout<<ans[i]<<" ";
	return 0;
} 
