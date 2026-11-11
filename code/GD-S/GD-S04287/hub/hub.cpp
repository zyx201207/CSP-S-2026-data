#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int read(){
	char ch=getchar();
	int x=0,y=1,cnt=5;
	while(ch<'0'||ch>'9'){
		if(ch=='-') y=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'&&cnt){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*y;
}
int head[N],to[N],ne[N],id;
void add(int x,int y){
	to[++id]=y,ne[id]=head[x],head[x]=id;
}
int c,t,n,k,l,r,mid,ans,sum,d[N],f[N];
void dfs(int u,int fa,int len){
	for(int i=head[u];i;i=ne[i]){
		int v=to[i];
		if(v==fa) continue;
		dfs(v,u,len);
		d[u]=max(d[v],d[u]);
	}
	d[u]++;
	if(d[u]==len) f[u]=1;
}
bool check(int len){
	dfs(1,0,len);
	sum=0;
	for(int i=1;i<=n;i++)
		if(f[i]==1) sum++;
	return sum<=k;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--){
		memset(head,0,sizeof(head));
		n=read(),k=read();
		for(int i=1,x,y;i<n;i++){
			x=read(),y=read();
			add(x,y),add(y,x);
		} 
		l=1,r=n-1,ans=mid=0;
		while(l<=r){
			mid=l+r>>1,sum=0;
			if(check(mid)){
				ans=mid,r=mid-1;
			}else{
				l=mid+1;
			}
			memset(d,0,sizeof(d));
			memset(f,0,sizeof(f));
		}
		printf("%d\n",ans);
	}
	return 0;
}
