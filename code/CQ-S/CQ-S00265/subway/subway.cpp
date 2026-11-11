#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int c,n,m,d,q,w[1000001],sum,f[1000001],l[100001];
struct st{
	int x,y;
};
vector<st> a[10001];
vector<int> z[100001];
void bfs(int x,int y){
	queue<int> q;
	for(int i=1;i<=m;i++){
		f[i]=0;
		l[i]=1e9;
	}
	sum+=w[x];
	q.push(x);
	f[x]=1;
	while(!q.empty()){
		int d=q.front(),minn=1e9;
		q.pop();
		for(int i=0;i<z[d].size();i++){
			for(int j=0;j<a[i].size();i++){
				int e=a[i][j].x;
				if(z[e].size()>1&&f[e]==0){
					q.push(e);
					f[e]=1;
					if(l[e]+a[i][j].y<l[d]){
						l[d]=l[e]+a[i][j].y;
					}
				}
			}
		}
	}	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[k].push_back({x,y});
			z[x].push_back(k);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		bfs(x,y);
		cout<<l[y]+w[y]+w[x]<<endl;
	}
	return 0;
}

