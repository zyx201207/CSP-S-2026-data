#include<bits/stdc++.h>
#define int long long
#ifdef int 
#define inf 0x3f3f3f3f3f3f3f3f
#else 
#define inf 0x3f3f3f3f
#endif
#define ulp(i,a,b) for(int i=a;i<=b;++i)
#define dlp(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
inline int read(){
	char c=getchar();
	bool f=false;
	int num=0;
	while(!isdigit(c)){
		if(c=='-')f=true;
		c=getchar();
	}
	while(isdigit(c)){
		num=(num<<1)+(num<<3)+(c^48);
		c=getchar(); 
	}
	return f?-num:num;
}
void write(int x,char ed=' '){
	if(x<0)putchar('-'),x=-x;
	int stk[65],top=0;
	do{
		stk[++top]=x%10;
		x/=10;
	}while(x);
	while(top)putchar(stk[top--]+'0');
	putchar(ed);
}
#define N 5005
int n,x[N],d;
int dis[N][N];
int cnt[N][N];
int f(int x){
	return x>0?x:-x;
}
void solve(){
	n=read(),d=read();
	ulp(i,1,n)x[i]=read();
	ulp(i,1,n)ulp(j,1,n)dis[i][j]=inf,cnt[i][j]=0;
	ulp(i,1,n){
		queue<int> q;
		q.push(i);
		dis[i][i]=0;
		cnt[i][i]=1;
		while(!q.empty()){
			int u=q.front();
			q.pop();
			ulp(v,1,n){
				if(v==u)continue;
				if(f(x[v]-x[u])<=d){
					if(dis[i][v]>dis[i][u]+1){
						dis[i][v]=dis[i][u]+1;
						cnt[i][v]=cnt[i][u];
						q.push(v);
					}
					else if(dis[i][v]==dis[i][u]+1){
						cnt[i][v]+=cnt[i][u];
					}
				}
			}
		}
	}
	int ans=0;
	ulp(i,1,n)ulp(j,i+1,n){
		ans+=(cnt[i][j]==2);
		//write(cnt[i][j],j==n?'\n':' ');
	}
	write(ans,'\n');
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read(),_=read();
	while(_--)solve();
	return 0;
}
