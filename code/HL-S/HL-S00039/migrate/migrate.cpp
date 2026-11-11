#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,T,n,d,x[N],ans,sum;
int e[N],ne[N],dis[N],flag[N],h[N],idx;
bool vis[N];
inline long long read(){
	long long f=1,sum=0;
	char c;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum*f;
}
void print(long long x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else print(x/10),putchar(x%10+'0');
}
inline void add(int a,int b){
	e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
void dfs(int u,int sum){
	//cout<<u<<" ";
	if(dis[u]<sum)return;
	if(dis[u]>sum)dis[u]=sum,flag[u]=1;
	else if(dis[u]==sum)flag[u]++;
	for(int i=h[u];~i;i=ne[i])dfs(e[i],sum+1);
}
void bfs(int s){
	queue<int> q;
	q.push(s);
	dis[s]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=h[u];~i;i=ne[i]){
			int v=e[i];
			if(dis[v]>dis[u]+1){
				flag[v]=1;
				dis[v]=dis[u]+1;
				q.push(v);
			}
			else if(dis[v]==dis[u]+1)flag[v]++;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--){
		ans=0;
		n=read(),d=read();
		for(int i=1;i<=n;i++)x[i]=read();
		if(c==11||c==12){
			int del=x[2]-x[1];
			if(d%del==0&&d/del!=1)print(n-2*d/del+1),printf("\n");
			else printf("0\n");
		}
		else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++)h[j]=-1,vis[j]=0,flag[j]=1,dis[j]=0x3f3f3f3f;
				idx=0;
				for(int j=i;j<=n;j++){
					int k=j+1;
					while(__int128(x[k])-__int128(x[j])<=__int128(d)&&k<=n)add(j,k++);
				}
				bfs(i);
				for(int j=i;j<=n;j++)if(flag[j]==2)ans++;
			}
			print(ans),printf("\n");
		}
	}
	return 0;
}