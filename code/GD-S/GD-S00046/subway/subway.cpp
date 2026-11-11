#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],a[50005][50005],t[50005][50005];
struct sta{
	int k,t;
};
queue <sta>qu;
int bfs(int start,int end){
	qu.push({start,0});
	while (1){
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d %d",&a[i][j],&t[i][j]);
		}
	}
	for(int i=1;i<=q;i++){
		int s,e;
		scanf("%d %d",&s,&e);
		cout<<bfs(s,e);
	}
	return 0;
} 
