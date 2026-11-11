#include <bits/stdc++.h>
using namespace std;
struct node{
	int v,t;
};
queue <node> q,q1;
int a[600][600];
int b[5005];
bool f[5000];
int c,n,m,d,r,k,x,y,sum=0;
void unit(){
	for(int i=1;i<=m;i++){
		f[i]=0;
	}
}
int bfs(int x,int t){
	if(x==y){
		return t;
	}
	int sum=1e9;
	for(int i=1;i<=m;i++){
		if(f[i]||a[x][i]==0){
			continue;
		}
		f[i]=1;
		int l=bfs(i,t+a[x][i]);
		sum=min(l,sum);
		f[i]=0;
	}
	return sum;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("substr.out","w",stdout);
	cin>>c>>n>>m>>d>>r;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		while(!q.empty()){
			q.pop();
		}
		for(int j=1;j<=k;j++){
			int v,t;
			cin>>v>>t;
			q1=q;
			q.push({v,t});
			while(!q1.empty()){
				int u=q1.front().v;
				int t1=t+q1.front().t;
				a[u][v]=t1;
				a[v][u]=t1;
				q1.pop();
			}
		}
	}
	for(int i=0;i<r;i++){
		cin>>x>>y;
		sum=b[x]+b[y];
		unit();
		f[x]=1;
		sum+=bfs(x,0);
		cout<<sum<<endl;
	}
	return 0;
}
