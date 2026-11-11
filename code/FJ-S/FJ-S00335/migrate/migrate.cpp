//T3
#include<bits/stdc++.h>
using namespace std;
#define int long long

int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f*x;
}

void out(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9)out(x/10);
	putchar(x%10+'0');
}
void write(int x){out(x);putchar(10);}
void wrote(int x){out(x);putchar(32);}

const int N=2e5+10;
const int inf=1e18;

int n,d,x[N];
int t,f;
int ans,res;

bool vis[N];

void dfs(int u,int cnt){
	if(cnt>ans)return ;
	if(u==t){
		if(cnt==res)f++;
		else if(cnt<res)res=cnt,f=1;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		if(abs(x[i]-x[u])>d)continue;
		vis[i]=1;
		dfs(i,cnt+abs(x[i]-x[u]));
		vis[i]=0;
	}
}

void init(){
	n=d=t=ans=0;
	res=inf;
	memset(vis,0,sizeof vis);
	memset(x,0,sizeof x);
}

signed main(){
//	freopen("migrate2.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int C=read();
	int T=read();
	while(T--){
		init();
		n=read(),d=read();
		for(int i=1;i<=n;i++)x[i]=read();
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=1;k<=n;k++)vis[k]=0;
				t=j,f=0;
				res=inf;
				vis[i]=1;
				dfs(i,0);
				if(f==2)ans++;
			}
		}
		write(ans);
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
