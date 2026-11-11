#include<bits/stdc++.h>
#define N 500005
using namespace std;
int c,n,m,d,Q,w[N],vis[N],h[N];
long long ans,minn;
vector<int> x[505],t[505];
queue<int> q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&Q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d",&h[j]);
			for(int l=1;l<j;l++){
				x[h[j]].push_back(h[l]);
				x[h[l]].push_back(h[j]);
			}
		}
		for(int j=1;j<=k;j++){
			scanf("%d",&h[j]);
			for(int l=1;l<j;l++){
				t[h[j]].push_back(h[l]);
				t[h[l]].push_back(h[j]);
			}
		}
	}
	for(int o=1;o<=Q;o++){
		int s,e;
		scanf("%d%d",&s,&e);
		q.push(s);
		minn=2e9;
		while(q.size()){
			int k=q.front();
			q.pop();
			for(int i:x[k]){
				if(vis[i]==0){
					
				}
			}
		}
		ans=min(minn,ans);
	}
	printf("%lld",ans);
	return 0;
}
