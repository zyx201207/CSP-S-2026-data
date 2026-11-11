#include<bits\stdc++.h>
using namespace std;
int c,n,m,d,Q,w[1000],t[1000][1000],a[1000][1000],k[1000],an=10000000;
int q[1000][1000]={-1},q2[1000][1000]={-1};
int dfs(int ans,int x,int y){
	if(x==y){
		an=min(an,ans);
		return ans;
	}
	for(int i=1;i<=m;i++){
		if(q2[x][i]!=-1&&q2[x][i]!=0){
			q2[x][i]=-1;
			dfs(ans+q[x][i],i,y);
			q2[x][i]=q[x][i];
		}
	}
	return ans;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(q,0,sizeof(q));
	memset(q2,0,sizeof(q2));
	cin>>c>>n>>m>>d>>Q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			q[i][a[i][j]]=t[i][j]+w[i]+w[j]+t[j][i];
			q2[i][a[i][j]]=q[i][a[i][j]];
		}
	}
	while(Q--){
		int xx,yy;
		an=10000000;
		cin>>xx>>yy;
		dfs(0,xx,yy);
		cout<<an<<"\n";
	}
	return 0;
}
