#include<bits/stdc++.h>
using namespace std;
int tid,t,n,m,dis[15];
bool flag[15];
vector<int> g[1000005];
void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
}
void dfs(int x,int fa){
	flag[x]=0;
	for(int y:g[x]){
		if(y==fa||!flag[y]) continue;
		dfs(y,x);
	}
}
bool check(int x){
	memset(flag,0,sizeof(flag));
	for(int i=1;i<=n;i++){
		if(x>>i-1&1) flag[i]=1;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(flag[i]) dfs(i,0),cnt++;
	}
	return cnt<=2;
}
queue<int> q;
void work(){
	int ans=n;
	for(int i=1;i<(1<<n);i++){
		if(__builtin_popcount(i)==m&&check(i)){
			while(!q.empty()) q.pop();
			memset(dis,-1,sizeof(dis));
			for(int j=1;j<=n;j++){
				if(i>>j-1&1) q.push(j),dis[j]=0;
			}
			while(!q.empty()){
				int x=q.front();
				q.pop();
				for(int y:g[x]){
					if(dis[y]==-1){
						dis[y]=dis[x]+1;
						q.push(y);
					}
				}
			}
			int cnt=0;
			for(int j=1;j<=n;j++){
				cnt=max(cnt,dis[j]);
			}
			ans=min(ans,cnt);
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read(tid),read(t);
	while(t--){
		read(n),read(m);
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			int x,y;
			read(x),read(y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		if(n<=10){
			work();
			continue;
		}
		if(tid==13||tid==14){
			int len=n/2+2;
			if(m==n) puts("0");
			else if(m>=n/2) puts("1");
			else{
				printf("%d\n",max(2,(len-m+3)/4));
			}
		}
	}
	return 0;
}
