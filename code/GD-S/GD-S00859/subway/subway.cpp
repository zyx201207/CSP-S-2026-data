#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qu,a[500001],b[500001][21],bsize[500001],vis[500001];
struct node{
	int x,t;
};
vector<int> xian[501],tim[501];
int dian[50001][501];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qu;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int n1,x,t;
		cin>>n1;
		for(int j=1;j<=n1;j++){
			cin>>x>>t;
			xian[i].push_back(x);
			tim[i].push_back(t);
			b[x][++bsize[x]]=i;
			dian[x][i]=j;
		}
	}
	int l,r;
	while(qu--){
		cin>>l>>r;
		if(l==r){
			cout<<"0\n";
			continue;
		}
		for(int i=1;i<=m;i++)vis[i]=1000000000;
		queue<node> q;
		q.push({l,a[l]});
		vis[l]=a[l];
		while(q.size()){
			node x=q.front();
			q.pop();
			for(int i=1;i<=bsize[x.x];i++){
				int y=b[x.x][i];
				for(int j=0;j<xian[y].size();j++){
					if(vis[xian[y][j]]>x.t+tim[y][dian[x.x][y]-1]+tim[y][j]){
						q.push({xian[y][j],x.t+tim[y][dian[x.x][y]-1]+tim[y][j]});
						vis[xian[y][j]]=x.t+tim[y][dian[x.x][y]-1]+tim[y][j];
					}
				}
			}
		}
		cout<<vis[r]+a[r]<<"\n";
	}
	return 0;
}
