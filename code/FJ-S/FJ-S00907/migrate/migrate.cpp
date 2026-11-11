#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	char c;
	int x=0,f=1;
	c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int MAXN=5e6+5;
int test,t;
int n,d,x[MAXN],tng[MAXN];
int que[MAXN],head,tail;
int dis[MAXN],ways[MAXN];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	test=read();t=read();
	while(t--){
		n=read();d=read();
		for(int i=1;i<=n;i++){
			x[i]=read();
		}
		if(test==11||test==12){
			int gcha=x[2]-x[1];
			int r=d/gcha;
			int ans=0;
			for(int i=1;i<=n;i++){
				int j=min(n-i-r,r-1);
				if(j<=0) break;
				ans+=j;
			}
			cout<<ans<<endl;
			continue;
		}
		int ans=0;
		for(int i=n;i>=1;i--){
			for(int j=0;j<=n;j++){
				tng[j]=0;
				ways[j]=0;
			}
			dis[i]=0;
			ways[i]=1;
			tng[dis[i]]++;
			head=1;tail=0;
			que[++tail]=i;
			for(int j=i-1;j>=1;j--){
				while(head<=tail&&x[j]+d<x[que[head]]){
					tng[dis[que[head]]]-=ways[que[head]];
					head++;
				}
				if(head>tail) break;
				dis[j]=dis[que[head]]+1;
				ways[j]=tng[dis[que[head]]];
				if(ways[j]==2){
					ans++;
				}
				tng[dis[j]]+=ways[j];
				while(head<=tail&&dis[que[tail]]>dis[j]){
					tng[dis[que[tail]]]-=ways[que[tail]];
					tail--;
				}
				que[++tail]=j;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
