#include<bits/stdc++.h>
using namespace std;
int c,t;
vector<int> v[100005];
struct node{
	int from,to,step;
};
int bfs(int start,int n){
	bool vis[100005];
	int sum[100005];
	int mi[100005];
	memset(vis,0,sizeof(vis));
	memset(sum,0,sizeof(sum));
	for(int i=1;i<n;i++)mi[i]=20000000;
	queue<node> q;
	node x;
	x.from=0,x.to=start;x.step=0;
	q.push(x);
	while(!q.empty()){
		x=q.front();
		q.pop();
		int to=x.to,step=x.step;
		if(vis[to]){
			if(step==mi[to])sum[to]+=sum[x.from];
			continue;
		}
		vis[to]=1;
		mi[to]=step;
		sum[to]=1;
		int m=v[to].size();
		for(int i=0;i<m;i++){
			int now=v[to][i];
			node ne;
			ne.from=to,ne.to=now;ne.step=step+1;
			q.push(ne);
		}
	}
	int ans;
	for(int i=1;i<=n;i++){
		if(sum[i]==2){
			//cout<<start<<' '<<i<<'\n';
			ans++;
		}
	}
	return ans;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n;
		long long d,a[100005],ans=0;
		cin>>n>>d;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=i-1;j>0;j--){
				if(a[i]-a[j]<=d){
					v[j].push_back(i);
					v[i].push_back(j);
					//cout<<i<<' '<<j<<'\n';
				}
				else break;
			}
		}
		for(int i=1;i<=n;i++){
			ans+=bfs(i,n);
		}
		cout<<ans/2<<'\n';
		for(int i=1;i<=n;i++)v[i].clear();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
