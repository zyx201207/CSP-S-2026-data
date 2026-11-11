#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[510], a[510][510], t[510][510], vis[510];
struct node{
	int v, w;
};
vector<int> ve[510];
queue<node> qq;
void init(){
	for(int i=1; i<=500; i++){
		vis[i]=0;
	}
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++){
		scanf("%d", &w[i]);
	}
	int f=0, ff=0;
	for(int i=1; i<=n; i++){
		int k;
		cin>>k;
		if(k>2){
			f=1;
		}
		for(int j=1; j<=k; j++){
			scanf("%d %d", &a[i][j], &t[i][j]);
			if(t[i][j]!=t[i][j-1] && j!=1){
				ff=1;
			}
			ve[a[i][j]].push_back(i);
		}
	}
	while(q--){
		int xr, yr;
		scanf("%d %d", &xr, &yr);
		if(f==0){
			vis[xr]=1;
			vis[0]=1;
			qq.push({xr, w[xr]+w[yr]});
			while(!qq.empty()){
				int x=qq.front().v;
				int st=qq.front().w;
				qq.pop();
				if(x==yr){
					printf("%d\n", st);
					while(!qq.empty()){
						qq.pop();
					}
					break;
				}
				for(int i=0; i<(int)(ve[x].size()); i++){
					int subw=ve[x][i];
					if(a[subw][1]==x){
						if(vis[a[subw][2]]==0){
							vis[a[subw][2]]=1;
							qq.push({a[subw][2], st+t[subw][1]+t[subw][2]});
						}
					}
					if(a[subw][2]==x){
						if(vis[a[subw][1]]==0){
							vis[a[subw][1]]=1;
							qq.push({a[subw][1], st+t[subw][1]+t[subw][2]});
						}
					}
				}
			}
			init();
		}
	}
	return 0;
} 
