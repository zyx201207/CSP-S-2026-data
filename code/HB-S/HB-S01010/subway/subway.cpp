#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[20005],k[505],a[505][20005],t[505][20005],ns[505][20005],minn=200000000,sum=0;
bool cs[505][20005],flg[505];
int ss,fs;
void dfs(int nk)
{
	if(nk==fs)
	{
		minn=min(sum,minn);
		return;
	}
	if(flg[nk]==1) return;
	for(int i=1;i<=n;i++)
	{
		if(cs[i][nk]==1)
		{
			sum+=t[i][nk];
			dfs(ns[i][nk]);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(flg,0,sizeof(flg));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k[i];j++)
		{
			cs[i][a[i][j]]=1;
			ns[i][a[i][j]]=a[i][j+1];
		}
	}
	
	for(int i=1;i<=q;i++)
	{
		cin>>ss>>fs;
		sum=w[ss]+w[fs];
		dfs(ss);
		cout<<minn<<endl;
	}
	return 0;
}
