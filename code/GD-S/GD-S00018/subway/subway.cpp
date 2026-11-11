#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct edge{
	int ne,w;
};
edge a[500005][25];
int w[500005];
int ed;
long long ans=100000000000;
int vis[500005];
int dp[2005][25];
void dfs(int x,int sum,int xian){
	//cout<<x<<" "<<sum<<" "<<xian<<endl;
	if(sum>dp[x][xian])return;
	dp[x][xian]=sum;
	if(x==ed){
		ans=min(1LL*sum+a[x][xian].w+w[x],ans);
		//cout<<endl;
		return;
	}
	for(int i=1;i<=d;i++){
		if(a[x][i].ne==0||vis[a[x][i].ne]==1){
			continue;
		}
		vis[x]=1;
		if(i==xian){
			//cout<<x<<"-->";
			dfs(a[x][i].ne,sum,xian);
		}
		//cout<<x<<","<<a[x][xian].w<<","<<a[x][i].w<<"->";
		dfs(a[x][i].ne,sum+a[x][xian].w+a[x][i].w,i);
		vis[x]=0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dp,0x3f,sizeof(dp));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		memset(dp,0x3f,sizeof(dp));
		int k;
		cin>>k;
		int px,ptt;
		for(int j=1;j<=k;j++){
			int x,tt;
			cin>>x>>tt;
			if(j!=1){
				a[px][i]={x,ptt};
				a[x][i]={px,ptt};
			}
			if(j==k){
				a[x][i]={0,tt};
			}
			px=x;
			ptt=tt;
		}
	}
	//cout<<a[5][1].w<<endl<<endl;
	while(q--){
		int l,r;
		cin>>l>>r;
		ed=r;
		ans=100000000000;
		for(int i=1;i<=d;i++){
			if(a[l][i].ne!=0){
				dfs(l,w[l]+a[l][i].w,i);
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
