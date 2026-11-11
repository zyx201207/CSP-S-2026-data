#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=505;
int n,m;
int c,d,q;             
int w[N];
int x,y;
int a[M],b1[M][1005],b2[M][1005];
vector<int> V[2005];
long long dis[N];
bool vis[N];
int w[1005][1005];
void spfa(int s,int t){
	dis[s]=0;
	queue<int> q;
	q.push(s);
	vis[s]=1;
	while(!q.empty()){
		int p=q.top();
		q.pop();
		for(int i=0;i<V[p].size();i++){
			if(dis[V[p][i]]>dis[i]+w[i][V[p][i]]){
			    dis[V[p][i]]=dis[i]+w[i][V[p][i]];
			    if(!vis[V[p][i]]) q.push(V[p][i]);
			}
		}
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
		cin>>a[i];
		for(int j=1;j<=a[i];j++){
			scanf("%d%d",&b1[i][j],&b2[i][j]);
		}
	}
	
	return 0;
}
