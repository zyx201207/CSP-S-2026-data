#include<bits/stdc++.h>
#define int long long
#ifdef __unix
#define getchar getchar_unlocked
#define putchar putchat_unlocked
#else
#define getchar _getchar_nolock
#define putchar _putchar_nolock
#endif
using namespace std;
int read(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	return k*f;
}
void write(int x){
	if(x==0) putchar('0');
	else{
		int pos=0;char stk[30]={0};
		while(x) stk[pos++]=x%10+'0',x/=10;
		while(pos--) putchar(stk[pos]);
	}putchar('\n'); 
}
const int N=5e5+10;
int n,m,d,Q,w[N];
vector<int>a[N];
int f,dis[N],vis[N];
void dij(int x,int y){
	queue<int>q;
	for(int i=1;i<=m;i++) dis[i]=INT_MAX,vis[i]=false;
	q.push(x),dis[x]=f;
	while(!q.empty()){
		int t=q.front();q.pop();
		if(vis[t]) continue;
		vis[t]=true;
		for(int i:a[t]){
			if(dis[i]>dis[t]+f)
				dis[i]=dis[t]+f,q.push(i);
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	n=read();
	n=read(),m=read(),d=read(),Q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		int k=read();
		int t1=read(),t2;
		f=read();
		for(int j=2;j<=k;j++){
			if(j%2==0) t2=read();
			else t1=read();
			f=read();
			a[t1].push_back(t2);
		}
	}
	while(Q--){
		int x=read(),y=read();
		dij(x,y);
		write(dis[y]+w[x]+w[y]);
	}
	return 0;
}

