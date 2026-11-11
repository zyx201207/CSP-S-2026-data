#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,k[N],last[N],suf[N],ans[N];
bool f[N],flag[N];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i-1];
//		if(last[k[i-1]])
//			for(int t=last[k[i-1]];t<i;t++) f[t]++;
		if(last[k[i-1]]) suf[last[k[i-1]]]=i;
		last[k[i-1]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		memset(f,false,sizeof f);
		memset(flag,false,sizeof flag);
		for(int t=i;t<=n;t++)
		{
			for(int j=i;j<t;j++)
				if(suf[j] && suf[j]>=t) f[t]=1;
			if(!f[t] && !flag[k[t-1]]) ans[k[t-1]]++,flag[k[t-1]]=1;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
