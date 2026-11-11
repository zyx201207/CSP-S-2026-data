#include<bits/stdc++.h>
using namespace std;
/*
void bfs(int s,int e){
	queue<int> q;
	int b[510]={0};
	q.push(s);
	b[s]=1;
	while(!q.empty()){
		int h=q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			
		}
	}
}
*/
int c,n,m,d,q,k[510];
int w[500010],a[510][510],t[510][510];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d %d",&a[i][j],&t[i][j]);
		}
	}
	while(q--){
		int x,y;
		long long cnt=0;
		scanf("%d %d",&x,&y);
		cnt=cnt+w[x]+w[y];
		int flag=0;
		for(int i=1;i<=n;i++){
			int f=0;
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x) f=1;
				if(a[i][j]==y && f==1){
					flag=1;
					break;
				}
			}
			if(flag) break;
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
