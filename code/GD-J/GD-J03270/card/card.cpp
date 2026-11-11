#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[5005],b[3005],c[3005],ans[3005];
bool vis[5005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]])
			{
				for(int k=c[a[j]];k<j;k++)
				{
					if(b[a[k]]&&!vis[k]) b[a[k]]--,vis[k]=1;
				} 
			}
			b[a[j]]++,c[a[j]]=j;
		}
		for(int j=1;j<=3000;j++) ans[j]+=b[j];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
/*
*/
