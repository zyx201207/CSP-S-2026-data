#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+6;
int c,t;
int n,k;
vector<int>E[N];

int tmp[N],cnt;

int dist[N];
bool vis[N];

bool vi[N],v1[N];

bool ok() {
//	for(int i=1;i<=cnt;i++) {
//		cout<<v1[tmp[i]]<<' ';
//	}
//	cout<<endl;
	
	for(int i=1;i<=cnt;i++) {
		if(!v1[tmp[i]]) {
			return false;
		}
	}
	return true;
}

bool pd() {
	int num=0;
	for(int i=1;i<=cnt;i++) {
		v1[tmp[i]]=false;
	}
	while(!ok()) {
//		cout<<"54188";
		num++;
		int pos=0;
		for(int i=1;i<=cnt;i++) {
			if(!v1[tmp[i]]) {
				pos=tmp[i];
				break;
			}
		}
		
		queue<int>q;
		q.push(pos);
		
		while(!q.empty()) {
			int u=q.front();
			q.pop();
			
			if(v1[u]) {
				continue;
			}
			v1[u]=true;
			
			for(int v : E[u]) {
				if(!vi[v]) {
					continue;
				}
				
				q.push(v);
			}
		}
	}
	return num<=2;
}

void bfs() {
	queue<int>q;
	for(int i=1;i<=cnt;i++) {
		q.push(tmp[i]);
		dist[tmp[i]]=0;
	}
	
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		
		if(vis[u]) {
			continue;
		}
		vis[u]=true;
		
		for(int v : E[u]) {
			if(dist[u]+1<dist[v]) {
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}
	return ;
}

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--) {
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) {
			E[i].clear();
		}
		
		for(int i=1,u,v;i<n;i++) {
			scanf("%d%d",&u,&v);
			E[u].push_back(v);
			E[v].push_back(u);
		}
		
		int minn=INT_MAX;
		for(int i=0;i<(1<<n);i++) {
			for(int j=1;j<=n;j++) {
				vi[j]=false;
			}
			cnt=0;
			for(int j=1;j<=n;j++) {
				if(i&(1<<(j-1))) {
					tmp[++cnt]=j;
					vi[j]=true;
				}
			}
			if(cnt!=k) {
				continue;
			}
//				for(int j=1;j<=cnt;j++) {
//					cout<<tmp[j]<<' ';
//				}
//				cout<<"\n";
			
			if(!pd()) {
				continue;
			}
			
			
			for(int j=1;j<=n;j++) {
				dist[j]=INT_MAX;
				vis[j]=false;
			}
			
			bfs();
			
			int maxx=0;
			for(int j=1;j<=n;j++) {
//					cout<<dist[j]<<' ';
				maxx=max(maxx,dist[j]);
			}
//				cout<<endl;
//				cout<<maxx<<endl;
			
			minn=min(minn,maxx);
		}
		printf("%d\n",minn);
	}
	return 0;
}
