#include<bits/stdc++.h>
using namespace std;

const int MAXN=4e3+10;
int c,t;
int n,k;
int f[MAXN][MAXN],e[MAXN][MAXN];
bool flag[MAXN];
int use[MAXN],nou[MAXN];
int ans;
queue<int> q;

void bfs(int s){
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		flag[use[u]]=1;
		for(int j=1;j<=k;j++){
			if(!flag[use[j]]&&e[use[j]][use[u]]){
				flag[use[j]]=true;
				q.push(j);
			}
		}
	}
}

int calc(){
	int cnt;
	memset(flag,0,sizeof(flag));
	for(int i=1;i<=k;i++){
		if(!flag[use[i]]){
			cnt++;
			bfs(i);
		}
		if(cnt>2) return 0x3f3f3f3f;
	}
	
	int ret=0;
	for(int i=1;i<=n;i++){
		int dist=0x3f3f3f3f;
		for(int j=1;j<=k;j++) dist=min(dist,f[i][use[j]]);
		ret=max(dist,ret);
	}
	ans=min(ans,ret);
	return ret;
}

void sa(){
	for(int tmp=10000;tmp>0.0001;tmp*=0.9995){
		int a=rand()%k+1,b=rand()%(n-k)+1;
		int now=calc();
		swap(use[a],nou[b]);
		int nxt=calc();
		if(nxt>=now&&exp(now-nxt)/t>(double)rand()/RAND_MAX) swap(use[a],nou[b]);
	}
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		memset(f,0x3f,sizeof(f));
		ans=0x3f3f3f3f;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			f[u][v]=f[v][u]=e[u][v]=e[v][u]=1;
		}
		if(n==k){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++) f[i][i]=0;
		for(int i=1;i<=k;i++) use[i]=i;
		for(int j=k+1;j<=n;j++) nou[j-k]=j;
		for(int kk=1;kk<=n;kk++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					f[i][j]=min(f[i][j],f[i][kk]+f[kk][j]);
				}
			}
		}
		sa();
		cout<<ans<<endl;
	}
	
	return 0;
}
