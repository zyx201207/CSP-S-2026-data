#include<bits/stdc++.h>
using namespace std;

int sum,ans=INT_MAX,c,n,m,d,p,w[5005],b[5005],k,a,t,map1[5005][505],map2[5005][5005];
int x,y;

void dfs(int xx){
	if(sum>ans)
	return;
	for(int i=1;i<=m;i++)
	{
		if(map2[xx][i]!=INT_MAX&&b[i]==0)
		{
			sum+=map2[xx][i];
			b[i]=1;
			if(i==y)
			ans=min(ans,sum);
			else
			dfs(i);
			sum-=map1[xx][i];
			b[i]=0;
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++)
	cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a>>t;
			map1[a][i]=t;
		}
	}
	for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++)
	{
		map2[i][j]=INT_MAX;
		for(int it=1;it<=n;it++)
		if(map1[i][it]>0&&map1[j][it]>0)
		map2[i][j]=min(map2[i][j],map1[i][it]+map1[j][it]);
	}
	
	while(p--){
		
		cin>>x>>y;
		sum=0;
		ans=INT_MAX;
		b[x]=1;
		dfs(x);
		cout<<w[x]+w[y]+ans<<endl;
	}
	return 0;
}
