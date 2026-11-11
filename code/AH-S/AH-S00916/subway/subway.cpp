#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
int w[500005],ans;
vector<int> vi[510],st[500005];
int zhan[500005][505];
int k[510];
bool vis1[500005],vis2[500];
void dfs(int start,int dis){
	if(start==y){
		ans=min(ans,dis);
		return;
	}
	int line=st[start].size();
	for(int i=0;i<line;i++){
		int k=st[start][i];
		if(vis2[k]==1)continue;
		int line2=vi[k].size();
		for(int j=0;j<line2;j++){
			if(vis1[vi[k][j]]==0){
				vis1[vi[k][j]]=1;
				vis2[k]=1;
				dfs(vi[k][j],dis+zhan[start][k]+zhan[vi[k][j]][k]);
				vis2[k]=0;
				vis1[vi[k][j]]=0;
			}
		}
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int num1,num2;
			scanf("%d%d",&num1,&num2);
			vi[i].push_back(num1);
			st[num1].push_back(i);
			zhan[num1][i]=num2;
		}
	}
	while(q--){
		scanf("%d%d",&x,&y);
		memset(vis1,0,sizeof vis1);
		memset(vis2,0,sizeof vis2);
		vis1[x]=1;
		ans=INT_MAX;
		dfs(x,0);
		ans+=w[x];
		ans+=w[y];
		printf("%d\n",ans);
	}
	return 0;
}
