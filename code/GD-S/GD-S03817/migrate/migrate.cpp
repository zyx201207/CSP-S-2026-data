#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::string;

const int N=2e6;
const int K=2e6;

int c,t,n,d,a[N],ans;

int cnt,to[K],head[N],pth[K],nxt[K],maxx;
void addedge(int u,int v,int w){
	nxt[++cnt]=head[u];
	to[cnt]=v;
	pth[cnt]=w;
	head[u]=cnt;
}

int dis[N],flg[N];

void Dijkstra(int start){
	memset(dis,0x3f3f3f,sizeof(dis));
	memset(flg,0,sizeof(flg));
	dis[start]=0;
	while(1){
		int u=0;
		for(int i=1;i<=n;i++){
			if(!flg[i]&&dis[i]<dis[u]) u=i;
		}
		if(u==0) break;
		flg[u]=1;
		
		for(int i=head[u];i;i=nxt[i]){
//			cout<<"Yes";
			int v=to[i],w=pth[i];
			if(!flg[v]&&dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
			}
		}
	}
}

int count(int s,int t,int sp){
	std::queue<std::pair<int,int> > que;
	que.push(std::make_pair(s,0));
	
	int cnnt=0;

	while(!que.empty()){
		std::pair<int,int> u=que.front();
		que.pop();
		
		if(u.first==t&&u.second==sp) cnnt++;
		
		for(int i=head[u.first];i;i=nxt[i]){
			int v=to[i],w=pth[i];
			que.push(std::make_pair(v,u.second+w));
		}
	}
	return cnnt;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	
	while(t--){
		ans=cnt=0;
		memset(head,0,sizeof(head));
		memset(nxt,0,sizeof(nxt));
		
		
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			int j=i-1;
			while(a[i]-a[j]<=d&&j>=1){
				addedge(j,i,1);
				j--;
			}
		}
		for(int s=1;s<=n;s++){
			Dijkstra(s);
			
			for(int t=s+1;t<=n;t++){
//				cout<<"dist("<<s<<","<<t<<")="<<dis[t]<<" ";
//				if(s>=t) continue;
				
				if(count(s,t,dis[t])==2) ans++;
			}
//			cout<<endl;
		} 
		
		cout<<ans<<endl;
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
