#include<bits/stdc++.h>
#define ll long long
#define Pii pair<int,int>
#define Pil pair<int,ll>
#define Fi first
#define Se second
using namespace std;
namespace IO{
	bool Isdigit(char c){return c>='0'&&c<='9';}
	template<typename T>inline void read(T &x){
		char c=getchar();bool f=0;x=0;
		while(!Isdigit(c)){if(c=='-')f=1;c=getchar();}
		while(Isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
		x=f?-x:x;
	}
}
using namespace IO;
const int N=1e6+10;
queue<int> Q;
int C,T,n,K,cnt,Be[N],Id[N],fa[N],U[N],V[N],head[N],To[N<<1],Nxt[N<<1];
void add(int from,int to){
	To[++cnt]=to;
	Nxt[cnt]=head[from];
	head[from]=cnt;
}
int Count(int x){
	int Res=0;
	while(x)Res++,x&=(x-1);
	return Res;
}
void IInit(){
	cnt=0;
	for(int i=1;i<=n;i++)head[i]=0;
}
void Init(){for(int i=1;i<=n;i++)fa[i]=i;}
int find(int i){return fa[i]==i?i:fa[i]=find(fa[i]);}
int dfs(int x,int f){
	if(Be[x])return 0;
	int Res=n+1;
	for(int i=head[x];i;i=Nxt[i])
		if(To[i]!=f)Res=min(Res,dfs(To[i],x));
	return Res+1;
}
void Solve(){
	read(n),read(K),IInit();
	for(int i=1;i<n;i++){
		read(U[i]),read(V[i]);
		add(U[i],V[i]),add(V[i],U[i]);
	}
	if(K==n)return puts("0"),void();
	int Ans=n+1;
	for(int S=1;S<(1<<n);S++)
		if(Count(S)==K){
			int idx=0,Res=0,tot=K;
			Init();
			for(int i=1;i<=n;i++)
				if(S>>(i-1)&1)
					Id[++idx]=i,Be[i]=1;
				else Be[i]=0;
			for(int i=1;i<n;i++)
				if(Be[U[i]]&&Be[V[i]]){
					int x=find(U[i]);
					int y=find(V[i]);
					if(x!=y)--tot,fa[x]=y;
				}
			if(tot>2)continue;
			for(int i=1;i<=n;i++)
				if(!Be[i])Res=max(Res,dfs(i,0));
			Ans=min(Ans,Res);
		}
	printf("%d\n",Ans);
}
void Solve_2(){
	read(n),read(K);
	int m=(n-1)/2;
	if(K==n)return puts("0"),void();
	if(K>=m)return printf("1\n"),void();
	int x=K/2,y=K-x,Res=n;
	for(int i=1;;i++){
		int r=i+x-1,L=m-y-i+2;
		if(r>L)break;
		Res=min(Res,max(i,(L-r)/2+1));
	}
	printf("%d\n",Res);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read(C),read(T);
	while(T--){
		if(C>=13&&C<=14)Solve_2();
		else Solve();
	}
}