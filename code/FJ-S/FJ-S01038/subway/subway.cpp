#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5,inf=0x3f3f3f3f;
int n,m,x,y,q,c,d,k;
int a[M],w[M];
int e[N][N],t[M];
bool vis[M];
vector<int> v,E[M];
queue<pair<int,long long> > Q;
void solveA(){
	for(int z:v) for(int i:v) for(int j:v)
		e[i][j]=e[j][i]=min(e[i][j],e[i][z]+e[z][j]);
	while(q--){
		scanf("%d%d",&x,&y);
		cout<<e[x][y]+w[x]+w[y]<<"\n";
	}
}
void solveB(){
	while(q--){
		long long ans;
		memset(vis,0,sizeof(vis));
		while(!Q.empty()) Q.pop();
		scanf("%d%d",&x,&y);
		Q.push(make_pair(x,0));
		vis[x]=1;
		while(!Q.empty()){
			int u=Q.front().first;
			long long T=Q.front().second;
			Q.pop();
			if(u==y){
				ans=T;
				break;
			}
			for(int p:E[u]){
				if(!vis[p]){
					vis[p]=1;
					Q.push(make_pair(p,T+2));
				}
			}
		}
		cout<<ans*t[1]+w[x]+w[y]<<endl;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	if(n==1){
		scanf("%d",&k);
		for(int j=1;j<=k;j++) scanf("%d%d",&a[j],&t[j]);
		while(q--){
			scanf("%d%d",&x,&y);
			cout<<t[x]+t[y]+w[x]+w[y]<<"\n";
		}
		return 0;
	}
	if(c<=8) memset(e,inf,sizeof e);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a[j],&t[j]);
			if(c<=8){
				v.push_back(a[j]);
				for(int z=1;z<j;z++) e[a[j]][a[z]]=e[a[z]][a[j]]=min(e[a[j]][a[z]],t[j]+t[z]);
			}
			else if(c>=12&&c<=19){
				for(int z=1;z<j;z++) E[a[j]].push_back(a[z]),E[a[z]].push_back(a[j]);
			}
		}
	}
	if(c<=8) solveA();
	else if(c>=12&&c<=19) solveB();
	return 0;
}