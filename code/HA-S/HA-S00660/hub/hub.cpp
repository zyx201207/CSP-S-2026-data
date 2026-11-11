#include<bits/stdc++.h>
using namespace std;
#define intt long long
namespace IO{
	inline intt read(){
		intt x=0,f=1;char ch=getchar();
		for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
		for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<3)+(x<<1)+ch-'0';
		return x*f;
	}
	inline void write(intt x){
		if(x<0)putchar('-'),x=-x;
		if(x>9)write(x/10);
		putchar(x%10+'0');return;
	}
	inline void print(intt x,bool fl=1){
		write(x);if(fl)putchar('\n');
		else putchar(' ');return;
	}
}using namespace IO;
namespace Code{
	#define For(i,a,b) for(int i=(a);i<=(b);i++)
	#define Rep(i,a,b) for(int i=(a);i>=(b);i--)
	#define pb push_back
	#define mk make_pair
	typedef pair<intt,intt>PII;
	typedef vector<intt>Vntt;
	const intt N=1e6+10;
	intt h[N],ver[N<<1],next[N<<1],idx;
	inline void add(intt u,intt v){
		ver[idx]=v;next[idx]=h[u];
		h[u]=idx++;return;
	}
	intt V[N],K[N];
	inline void dfs(intt u,intt f){
		if(!K[u])return;
		V[u]=1;
		for(int i=h[u];~i;i=next[i]){
			intt v=ver[i];
			if(v==f)continue;
			dfs(v,u);
		}return;
	}
	inline bool check(intt n){
		For(i,1,n)V[i]=0;
		intt cnt=0;
		For(i,1,n)if(!V[i]&&K[i]){
			dfs(i,0);cnt++;
		}return cnt<=2;
	}
	intt dep[N]; 
	inline intt calc(intt n){
		queue<intt>Q;
		For(i,1,n)dep[i]=1e18;
		For(i,1,n)if(K[i]){
			Q.push(i);dep[i]=0;
		}
		intt Ans=0;
		while(!Q.empty()){
			intt u=Q.front();Q.pop();
			for(int i=h[u];~i;i=next[i]){
				intt v=ver[i];
				if(dep[v]!=1e18)continue;
				dep[v]=dep[u]+1;
				Q.push(v);
				Ans=max(Ans,dep[v]);
			}
		}return Ans;
	}
	intt Ans;
	inline void solve(intt x,intt k,intt n){
		if(x==n+1){
			if(k)return;
			if(check(n))Ans=min(Ans,calc(n));
			return;
		}
		K[x]=1;
		if(k)solve(x+1,k-1,n);
		K[x]=0;
		solve(x+1,k,n);
	}
	inline void main(){
		intt n=read(),k=read();
		memset(h,-1,sizeof(h));
		For(i,2,n){
			intt u=read(),v=read();
			add(u,v);add(v,u);
		}
		Ans=1e18;
		solve(1,k,n);
		print(Ans,1);
		return;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	intt c=read(),t=read();
	while(t--)Code::main();
	return 0;
}

