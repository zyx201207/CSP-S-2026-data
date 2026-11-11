#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,len,k;
int x[2000005];
bool vis[2000005];
struct node{
	int now,dis;
};
int dis1(int start,int end){
	vis[start]=1;
	queue<node> q;
	q.push({start,0});
	while(!q.empty()){
		node u=q.front();
		q.pop();
		if(u.now==end){
			return u.dis;
		}
		for(int i=1;i<=n;i++){
			if(vis[i]==1)continue;
			if(abs(x[u.now]-x[i])>d)continue;
			q.push({i,u.dis+1});
			vis[i]=1;
		}
	}
}
void dis2(int now,int end,int dis){
	if(now==end){
		if(dis==len)k++;
		return;
	}
	if(dis>len)return;
	for(int i=1;i<=n;i++){
		if(vis[i]==1)continue;
		if(abs(x[now]-x[i])>d)continue;
		vis[i]=1;
		dis2(i,end,dis+1);
		vis[i]=0;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		int ans=0;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				memset(vis,0,sizeof vis);
				len=dis1(i,j);
				memset(vis,0,sizeof vis);
				k=0;
				dis2(i,j,0);
				if(k==2)ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
