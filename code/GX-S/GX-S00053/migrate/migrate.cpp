#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5010;
const int inf=1<<30;
inline int lb(const int& x){return x&(-x);}

int n,ans,wl[N],f[N],dis[N],c[N],ar[N];
ll d,a[N];

void add(int x,int val){
	while(x){
		c[x]=min(c[x],val);
		x-=lb(x);
	}
}

int sum(int x){
	int mn=inf;
	while(x<=n){
		mn=min(mn,c[x]);
		x+=lb(x);
	}
	return mn;
}

inline void solve(){
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);

	for(int i=1;i<=n;i++){
		int l=0,r=i;
		while(l<r-1){
			int mid=(l+r)>>1;
			if(a[i]-a[mid]<=d) r=mid;
			else l=mid;
		}
		wl[i]=r;
	}
//	for(int i=1;i<=n;i++)
//		printf("%d ",wl[i]);
//	puts("");

	ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			c[j]=inf;
		for(int j=1;j<=n;j++)
			ar[j]=0;

		add(i,0);
		dis[i]=0;
		ar[0]=i;
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[j-1]>d) break;
			dis[j]=sum(max(wl[j],i))+1;
			add(j,dis[j]);
			ar[dis[j]]=j;
		}

//		printf("%d\n",i);
//		for(int j=1;j<=n;j++)
//			printf("%d ",dis[j]);
//		puts("");
//		for(int j=1;j<=n;j++)
//			printf("%d ",ar[j]);
//		puts("");

		for(int j=1;j<=n;j++)
			f[j]=0;
		f[i]=1;
		for(int j=i+1;j<=n;j++){
			if(a[j]-a[j-1]>d) break;
			f[j]=f[min(ar[dis[j]-1],j-1)]-f[max(wl[j],i)-1];
//			printf("%d %d\n",min(ar[dis[j]-1],j-1),max(wl[j],i));
			if(f[j]==2) ans++;
			f[j]+=f[j-1];
		}
//		for(int j=1;j<=n;j++)
//			printf("%d ",f[j]-f[j-1]);
//		puts("");
	}
	printf("%d\n",ans);
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,tt;
	scanf("%d%d",&c,&tt);
	while(tt--){
		solve();
	}
}
