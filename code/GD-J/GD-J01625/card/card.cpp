#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
int a[N],lst[N],bj[N],in[N],sum[N];
vector<int> g[N];
queue<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		lst[i]=bj[a[i]],bj[a[i]]=i;
		if(lst[i]) g[lst[i]].push_back(i),in[i]++;
	}
	for(int i=1;i<=m;i++)
		if(bj[i]<n&&bj[i])
			g[bj[i]].push_back(bj[i]+1),in[bj[i]+1]++;
	for(int i=1;i<=n;i++){
		if(!in[i]) q.push(i);
		sum[i]=1;
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<int(g[u].size());i++){
			int v=g[u][i];
			sum[v]+=sum[u],in[v]--;
			if(!in[v]) q.push(v);
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",sum[bj[i]]);
	return 0;
}

