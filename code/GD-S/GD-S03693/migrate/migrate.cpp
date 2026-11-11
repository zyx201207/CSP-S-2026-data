#include <bits/stdc++.h>
#define int long long
#define MAXN 2000005
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
void print(int x){
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
int ct,t,n,d,a[MAXN],deg[MAXN];
int pl[MAXN],pr[MAXN],dis[MAXN],fr[MAXN],du[MAXN];
vector<int>e[MAXN];
queue<int>q;
void sol(){
	n=read(),d=read();
	for(int i=1;i<=n;i++)a[i]=read(),e[i].clear();
	for(int i=1;i<=n;i++)deg[i]=du[i]=0;
	for(int i=1;i<=n;i++){
		pl[i]=pr[i]=-1;
		int l=1,r=i-1;
		while(l<=r){
			int mid=l+r>>1;
			if(a[i]-a[mid]<=d)r=mid-1,pl[i]=mid;
			else l=mid+1;
		}
		l=i+1,r=n;
		while(l<=r){
			int mid=l+r>>1;
			if(a[mid]-a[i]<=d)l=mid+1,pr[i]=mid;
			else r=mid-1;
		}
	}
	int ans=0;
	for(int i=n;i>=1;i--){
		for(int j=i;j<=n;j++)dis[j]=1e9,deg[j]=du[j],fr[j]=0;
		for(int j=i+1;j<=pr[i];j++){
			e[i].push_back(j);
			deg[j]++,du[j]++;
		}
		q.push(i),dis[i]=0,fr[i]=1;
		while(!q.empty()){
			int t=q.front();
			q.pop();
			for(int y:e[t]){
				--deg[y];
				if(dis[y]>dis[t]+1)dis[y]=dis[t]+1,fr[y]=fr[t];
				else if(dis[y]==dis[t]+1)fr[y]+=fr[t];
				if(!deg[y])q.push(y);
			}
		}
		for(int j=i+1;j<=n;j++)if(fr[j]==2)ans++;
	}
	printf("%lld\n",ans);
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&ct,&t);
	while(t--)sol();
	return 0;
}
