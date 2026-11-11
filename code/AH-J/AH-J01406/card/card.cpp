#include<Bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],same[N],pre[N],ans[N];
int l[N];
bool vis[N];
int read(){
	int f=1,x=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+(c^48),c=getchar();
	return f*x;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;){
		int j=i;
		for(;j<=n&&a[i]==a[j];j++) same[i]++;
		i=j;
	}
	for(int i=1;i<=n;i+=same[i]){
		memset(pre,0,sizeof(pre));
		memset(vis,0,sizeof(vis));
		for(int j=i+1;j<=n;j++) l[j]=j-1;
		l[i]=0;
		for(int j=i;j<=n;j++){
			if(pre[a[j]]){
				l[j]=l[pre[a[j]]];
				for(int k=pre[a[j]];k<j;k++) pre[a[k]]=0;
			}
			pre[a[j]]=j;
		}
		for(int j=n;j;j=l[j]) if(!vis[a[j]]) ans[a[j]]+=same[i],vis[a[j]]=1;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
