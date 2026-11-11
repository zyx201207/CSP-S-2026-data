#include<bits/stdc++.h>
using namespace std;
long long c,n,m,w,k,ma[1000001];
int a[100001],vis[20001][20001],head[20001][21],cnt[100001],ans;
void dfs(int x,int y,int z){
	if(x==y){
		if(z<ans){
			ans=z;
			return ;
		}
	}
	for(int i=1;i<=cnt[x];i++){
		if(ma[head[x][i]]==0){
			ma[head[x][i]]=1;
			z+=vis[100001][head[x][i]];
			dfs(head[x][i],y,z);
			ma[head[x][i]]=0;
		}
	}
}
int main(){
	freopen("subway.in","r");
    freopen("subway.out","r");
	cin>>c>>n>>m>>w>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	int t;
	for(int i=1;i<=n;i++){
		cin>>t;
		while(t--){
			int x;
			cin>>x;
			cin>>vis[i][x];
			cnt[i]++;
			cnt[x]++;
			head[i][cnt[i]]=x;
			head[x][cnt[x]]=i;
		}
	}
		
	for(int qq=1;qq<=k;qq++){
		ans=1e7;
		int x,y;
		cin>>x>>y;
	    dfs(x,y,0);
		cout<<ans+a[x]+a[y]<<endl;
	}
	
	return 0;
}
