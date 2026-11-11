#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long c,n,m,d,q,vmax;
long long w[N],k[505],a,t;
int cnt[505][N];
long long ans[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>k[i];
		vmax=max(vmax,k[i]);
		for(long long j=1;j<=k[i];j++)
		{
			cin>>a>>t;
			cnt[a][i]=t;
		}
	}
	memset(ans,0x3f3f3f3f,sizeof ans);
	for(int i=1;i<=vmax;i++)
	{
		long long tt[25],ttt=0;
		for(int j=1;j<=n;j++)
		{
			if(cnt[j][i]!=0)
			{
			   ttt++;
			   tt[ttt]=j;
			}
		}
		for(int j=1;j<=ttt;j++)
		{
	        for(int k=j+1;k<=ttt;k++)
	        {
	        	int jj=tt[j],kk=tt[k];
	        	ans[jj][kk]=min(ans[jj][kk],(long long)cnt[jj][i]+cnt[kk][i]);
	        	ans[kk][jj]=ans[jj][kk];
			}
		}
	}
	while(q--!=0)
	{
		  int x,y;
		  cin>>x>>y;
		  long long vmin=INT_MAX;
		  long long tt1[25],ttt1=0;
		for(int j=1;j<=n;j++)
		{
			if(ans[x][j]!=0)
			{
			   ttt1++;
			   tt1[ttt1]=j;
			}
		}
		long long tt2[25],ttt2=0;
		for(int j=1;j<=n;j++)
		{
			if(ans[y][j]!=0)
			{
			   ttt2++;
			   tt2[ttt2]=j;
			}
		}
		for(long long j=1;j<=ttt1;j++)
		{
	        for(long long k=1;k<=ttt2;k++)
	        {
	        	vmin=min(vmin,ans[tt1[j]][tt2[k]]);
			}
		}
		  cout<<vmin+w[x]+w[y]<<" ";
	}
	return 0;
}

