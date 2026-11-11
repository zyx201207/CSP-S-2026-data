#include<bits/stdc++.h>
using namespace std;
int ans=1e9,c,n,m,d,q,w[500005],k[505],r,rrx,rry,b[500005],a2[5005][505],rr[5005];
vector<int>a[505],t[505];
void dfs(int x,int y,int sum)
{
	if(x==y)
	{
		ans=min(ans,sum);
		return ;
	}
	for(int i=1;i<=rr[x];i++)
	{
		int ss=0;
		for(int j=0;j<a[a2[x][i]].size();j++)
		{
			if(a[a2[x][i]][j]==x)
			{
				ss=t[a2[x][i]][j];
			}
		}
		for(int j=0;j<a[a2[x][i]].size();j++)
		{
			if(a[a2[x][i]][j]!=x&&b[a[a2[x][i]][j]]==0)
			{
				b[a[a2[x][i]][j]]=1;
				dfs(a[a2[x][i]][j],y,sum+t[a2[x][i]][j]+ss);
				b[a[a2[x][i]][j]]=0;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	    {
		    cin>>k[i];
			for(int j=1;j<=k[i];j++)
			{
				cin>>r;
				rr[r]++;
				a2[r][rr[r]]=i;
				a[i].push_back(r);
				cin>>r;
				t[i].push_back(r);
			}
		}
	while(q--)
	{
		cin>>rrx>>rry;
		dfs(rrx,rry,0);
		cout<<ans+w[rrx]+w[rry]<<"\n";
	}
	return 0;
}
