#include<bits/stdc++.h>
using namespace std;
int n,m,mx,a[200001],b[200001],k[200001],cnt,sum[35];
bool vis[35][200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cnt=n;
	for(int i=1;i<=n;i++) cin>>a[i],k[i]=1;
	for(int i=1;i<=n;i++)
	{
		int x=a[i],step=0;
		while(x)
		{
			vis[++step][i]=x&1;
			x>>=1;
		}
		mx=max(mx,step);
	}
	while(cnt>m)
	{	
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++)
		{
			if(k[i]==0) continue;
			int x=a[i],step=0;
			while(x)
			{
				sum[++step]+=x&1;
				x>>=1;
			}
		}
		bool f=0;
		for(int i=mx;i>=1;i--)
		{
			if(sum[i]>=m)
			{
				f=1;
				for(int j=1;j<=n;j++)
				{
					if(!k[j]) continue;
					if(vis[i][j]==0) k[j]=0,cnt--;
				}
				mx=i-1;
				break;
			}
		}
		if(!f||cnt==m) break;
	}
	int ans=INT_MAX,tot=0;
	for(int i=1;i<=n;i++)
	{
		if(k[i])
		{
			ans&=a[i];
			tot++;
		}
		if(tot==m) continue;
	}
	cout<<ans;
	return 0;
} 
