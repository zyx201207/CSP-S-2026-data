#include<bits/stdc++.h>
using namespace std;
long long vis[500010];
int n,m,c,d,q,k,x,y,w[500010],a[500][500010],p=-1,sum[500010];
queue<int> qu;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=-1;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			a[i][x]=y;
		}
		p=max(p,k);
	}
	while(q--){
		for(int i=1;i<=m;i++) vis[i]=INT_MAX;
		for(int i=1;i<=m;i++) sum[i]=0;
		while(!qu.empty()) qu.pop();
		cin>>x>>y;
		qu.push(x);
		vis[x]=w[x];
		while(!qu.empty()){

			int cur=qu.front();qu.pop();
			if(cur==y){
				break;
			}
			for(int i=1;i<=n;i++){
				if(a[i][cur]!=-1){
					for(int j=1;j<=m;j++){
						if(j!=cur){
							if(a[i][j]!=-1){
								if(sum[j]==0){
									qu.push(j);
									sum[j]++;
									//cout<<cur<<' '<<j<<' '<<vis[j]<<endl;
									vis[j]=min(vis[j],a[i][cur]+a[i][j]+vis[cur]);
								}
							}
						}
					}
				}
			} 
		}
		cout<<vis[y]+w[y]<<endl;
	} 
	
}
