#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int c,n,m,d,q;
int a[5005][5005],z[5005],cc[5005],book[5005];
int s,e,ans,cnt;
void dfs(int p,int step,int way)
{
	if(p==e)
	{
		cnt=min(cnt,step+a[way][p]);
		return;
	}
	step+=a[way][p];
	for(int i=1;i<=n;i++){
		if(a[i][p]!=0)
		{
			for(int j=1;j<=m;j++)
			{
				if(book[j]==0&&a[i][j]!=0)
				{
					book[j]=1;
					if(i!=way)
				    dfs(j,step+a[i][p],i);
				    else
				    dfs(j,step,i);
			    }
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	cin>>z[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;
			cin>>x>>y;
			a[i][x]=y;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>s>>e;
		memset(book,0,sizeof(book));
		ans=z[s]+z[e];
		cnt=INT_MAX;
		book[s]=1;
		dfs(s,0,1);
		cout<<ans+cnt<<endl;
	}
	return 0;
}
