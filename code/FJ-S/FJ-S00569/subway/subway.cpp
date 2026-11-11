#include<bits/stdc++.h>
using namespace std;

int cc,n,m,dd,q;
int b[500005];
long long d[505];
long long book[505][505];
vector<pair<int,long long> > a[500005];
vector<pair<int,long long> > c[505];

void bbd(int s,int l){
	int vis[505];
	memset(vis,0,sizeof(vis));
	memset(d,0x3f3f3f,sizeof(d));
	d[s]=0;
	if(l==s) return;
/*	for(int i=1;i<=n;i++){
		for(int j=0;j<(int)c[i].size();j++){
			int v=c[i][j].first;
			long long w=c[i][j].second;
			d[v]=min(d[v],d[w]+d[i]);
		}
	}*/
	priority_queue<int,vector<int>,greater<int> > q;
	q.push(s);
//	cout<<"*";
//	int qi=0;
	
	while(!q.empty()){
	//	qi++;
//		if(qi>=50) break;
		int now=q.top();
		q.pop();
		cout<<vis[now];
		
		while(vis[now]!=0 && !q.empty()){
			now=q.top();
			q.pop();
		}
		vis[now]=1;
		for(int i=0;i<(int)c[now].size();i++){
			int v=c[now][i].first;
			long long w=c[now][i].second;
			d[v]=min(d[v],d[now]+w);
			q.push(v);
		}
	}
//	return;
	for(int i=1;i<=n;i++){
//		cout<<d[i]<<" ";
	}
//	cout<<"\n";
	return;
}

clock_t st,dt;
int main(){
	freopen("subway1.in","r",stdin);
	freopen("subway1.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	st=clock();
	cin>>cc>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
//	cout<<"**";
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		for(int j=1;j<=num;j++){
			int aa,tt;
			cin>>aa>>tt;
			a[aa].push_back({i,tt});
			for(int k=0;k<a[aa].size();k++){
				int v=a[aa][k].first;
				book[i][k]+=tt;
				book[k][i]+=tt;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(book[i][j]==0) continue;
			c[i].push_back({j,book[i][j]});
			c[j].push_back({i,book[i][j]});
		}
	}
//	cout<<"***";
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		long long ans=1e15;
		for(int j=0;j<(int)a[u].size();j++){
			for(int k=0;k<(int)a[v].size();k++){
				int uu=a[u][j].first,vv=a[v][k].first;
				bbd(uu,vv);
				ans=min(ans,d[vv]+a[u][j].second+a[v][k].second);
			}
		}
//		cout<<ans+b[u]+b[v]<<"***\n";
	}
	dt=clock();
//	cerr<<double(dt-st);
return 0;
}
