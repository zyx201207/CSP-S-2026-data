#include<bits/stdc++.h>
using namespace std;
long long w[20010],f[510][20010],v[510][20010],k[510],l[20010][510],num[20010];
long long ans[20010];
int x,y;
bool check[510];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>f[i][j]>>v[i][j];
			num[f[i][j]]++;
			l[f[i][j]][num[f[i][j]]]=i;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		for(int i=1;i<=m;i++){
			check[i]=0;
			ans[i]=5000010;
		}
		check[x]=1,ans[x]=0;
		queue<int>q;
		q.push(x);
		while(!q.empty()){
			int u=q.front();
			for(int i=1;i<=num[u];i++){
				int line=l[u][i],id;
				for(int j=1;j<=k[line];j++){
					int to=f[line][j];
					if(to==u)id=j;
				}
				for(int j=1;j<=k[line];j++){
					int to=f[line][j];
					if(to==u)continue;
					if(v[line][j]+ans[u]+v[line][id]<ans[to]){
						if(!check[to]){
							q.push(to);
							check[to]=1;
						}
						ans[to]=v[line][j]+ans[u]+v[line][id];
					}
				}
			}
			q.pop();
			check[u]=0;
		}
		cout<<ans[y]+w[x]+w[y]<<endl;
	}
	return 0;
} 
