#include<bits/stdc++.h>
using namespace std;
int C; 
int n,m,p,q;
int smallestanswer=INT_MAX;
bool a[1005][1005];
int b[1005],zd[1005];
struct node{
	int p;
	int w;
};
queue <node> qq;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d",&C);
	scanf("%d",&n);scanf("%d",&m);scanf("%d",&p);scanf("%d",&q);
	for(int i=0;i<m;i++){
		scanf("%d",&zd[i]);
	}
	for(int i=0;i<n;i++){
		int w,e,ww,ee;
		scanf("%d",&w);
		scanf("%d%d%d%d",&w,&e,&ww,&ee);
		a[w-1][ww-1]=1;
		a[ww-1][w-1]=1;
		b[w-1]=e;
		b[ww-1]=ee;
	}
	while(q--){
		smallestanswer=INT_MAX;
		int u,v;
		cin>>u>>v;
		while(!qq.empty()){
			qq.pop();
		}
		qq.push({u-1,zd[u-1]+zd[v-1]+b[u-1]+b[v-1]});
		while(!qq.empty()){
			node nod=qq.front();
			qq.pop();
			if(nod.p==v-1){
				smallestanswer=min(smallestanswer,nod.w);
			}
			for(int i=0;i<m;i++){
				if(a[nod.p][i]){
					qq.push({i,nod.w+b[nod.p]+b[i]});
				}
			}
		}
		printf("%d",smallestanswer);
	}
	return 0;
}
