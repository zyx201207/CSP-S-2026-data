#include<bits/stdc++.h>
#define N 2000005
#define int long long
using namespace std;
inline int read(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?-x:x;
}
int c,T,n,d,x[N];
int now[N],ans[N];
bool vis[N];
void dfs(int u,int len){
	if(now[u]>len){
		now[u]=len;
		ans[u]=1;
	}
	else if(now[u]==len){
		ans[u]++;
	}
	for(int i=u+1;i<=n;i++){
		if(vis[i])continue;
		if(abs(x[i]-x[u])<=d){
			vis[i]=1;
			dfs(i,len+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),d=read();
		for(int i=1;i<=n;i++){
			x[i]=read();
		}
		if(c==1||c==2){
			for(int i=1;i<=n;i++){
				vis[i]=0;
				ans[i]=0;
				now[i]=0x3f3f3f3f3f3f3f3f;
			}
			int Ans=0;
			for(int i=1;i<=n;i++){
				dfs(i,0);
				for(int j=1;j<=n;j++){
					if(ans[j]==2)++Ans;
				}
				for(int j=1;j<=n;j++){
					ans[j]=0;
				}
			}
			cout<<Ans<<"\n";
		}
		if(c==11||c==12){
			int D=x[2]-x[1];
			int p=d/D;
			int ans=0;
			for(int i=1;i<=n;i++){
				if(p>1&&i+2*p-1<=n)++ans;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}

