#include<bits/stdc++.h>
using namespace std;
#define N 2000005
#define ll long long
int c,T,n,f[N],d[N],b[N],v[N];
ll a[N],k,ans;
void dfs(int x,int st){
	if(d[x]==N)
		d[x]=st;
	if(st>d[x])
		return;
	if(st==d[x])
		b[x]++;
	for(int i=f[x];i>x;i--)
		dfs(i,st+1);
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c==11||c==12){
		while(T--){
			scanf("%d %lld",&n,&k);
			for(int i=1;i<=n;i++)
				scanf("%lld",&a[i]);
			if(k>=(a[2]-a[1])*2)
				printf("%lld\n",max(0ll,n-k/(a[2]-a[1])*2+1));
			else printf("0\n");
		}
		return 0;
	}
	while(T--){
		scanf("%d %lld",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1,l=1;i<=n;i++){
			while(a[l]-a[i]<=k&&l<=n)
				l++;
			f[i]=l-1;
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				b[j]=v[j]=0;
				d[j]=N;
			}
			dfs(i,0);
			for(int j=i+1;j<=n;j++)
				if(v[j]==0&&b[j]==2)
					ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
