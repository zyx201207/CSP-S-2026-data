#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],cd[200005],vis[200005],bc[200005],js[35],zc,maxx,mc[35];
bool s[200005][35];
void cf(long long x,int i){
	if(x==0)
		s[i][++cd[i]]=0;
	while(x)
		s[i][++cd[i]]=x%2,x/=2;
}
void dfs(long long x){
	if(x>m){
		long long w=0;
		for(int i=1;i<=maxx;i++)
			js[i]=s[bc[1]][i];
		for(int i=2;i<=m;i++)
			for(int j=1;j<=maxx;j++)
				js[j]&=s[bc[i]][j];
		for(int i=1;i<=maxx;i++)
			if(js[i]==1)
				w+=mc[i];
		maxx=max(maxx,w);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		bc[x]=i;
		dfs(x+1);
		bc[x]=0;
		vis[i]=0;
	}
}
void mn(){
	mc[1]=1;
	for(int i=2;i<=31;i++)
		mc[i]=mc[i-1]*2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	mn();
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),cf(a[i],i),zc=max(zc,cd[i]),maxx=max(maxx,a[i]);
	if(m==1){
		printf("%lld",maxx);
		return 0;
	}
	if(m==2 && n<=2000){
		maxx=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				maxx=max(maxx,(a[i]&a[j]));
		printf("%lld",maxx);
		return 0;
	}
	printf("0");
	//dfs(1);
	//printf("%lld",maxx);
	return 0;
}
