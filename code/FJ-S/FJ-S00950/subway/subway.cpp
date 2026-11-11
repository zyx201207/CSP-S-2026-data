#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int c,n,m,d,Q;
int w[500005];
int k[505];
vector<int> a[505];
int ds[505][500005];
queue<int> q;
vector<int> h[500005];
long long dis[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].reserve(k[i]+5);
		for(int j=1;j<=k[i];j++){
			int x;
			cin>>a[i][j]>>x;
			h[a[i][j]].push_back(i);
			ds[i][a[i][j]]=x;
		}
	}
	while(Q--){
		int x,y;
		cin>>x>>y;
		memset(dis,0x3f,sizeof(dis));
		dis[x]=0;
		q.push(x);
		while(!q.empty()){
			int t=q.front();
			q.pop();
			for(int c:h[t]){
				int l=k[c];
				for(int i=1;i<=l;i++){
					int to=a[c][i];
					if(to!=1&&dis[to]==0x3f3f3f3f3f3f3f3fll){
						q.push(to);
					}
					dis[to]=min(dis[to],dis[t]+ds[c][t]+ds[c][to]);
				}
			}
		}
		cout<<dis[y]+w[x]+w[y]<<endl;
	}
	return 0;
}

