#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e6;
const int INF=1e9;
int c,T,n;
long long d,x[MAXN+10];
long long ans;
queue<int>q;
int calc(int i) {
	int l=i,r=n,res=i;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(x[mid]-x[i]<=d) {
			l=mid+1;
			res=mid;
		} else {
			r=mid-1;
		}
	}
	return res;
}
int dis[MAXN+10],f[MAXN+10];
bool sign[MAXN+10];
void wrk1(int s) {
	for(int i=s; i<=n; i++) {
		dis[i]=INF;
		f[i]=0;
		sign[i]=false;
	}
	dis[s]=0;
	f[s]=1;
	sign[s]=true;
	q.emplace(s);
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		int t=calc(u);
		for(int i=t; i>u; i--) {
			if(dis[i]>dis[u]+1) {
				dis[i]=dis[u]+1;
				f[i]=f[u];
				if(!sign[i]) {
					q.emplace(i);
					sign[i]=true;
				}
			} else if(dis[i]==dis[u]+1) {
				f[i]+=f[u];
				if(f[i]>2) {
					f[i]=3;
				}
			}
		}
	}
	for(int i=s; i<=n; i++) {
		if(f[i]==2) {
			++ans;
		}
	}
	return;
}
int lim[MAXN+10];
void wrk2(int s) {
	for(int i=s; i<=n; i++) {
		dis[i]=INF;
		f[i]=0;
		sign[i]=false;
	}
	dis[s]=0;
	f[s]=1;
	sign[s]=true;
	q.emplace(s);
	while(!q.empty()) {
		int u=q.front();
		q.pop();
		for(int i=lim[u]; i>u; i--) {
			if(dis[i]>dis[u]+1) {
				dis[i]=dis[u]+1;
				f[i]=f[u];
				if(!sign[i]) {
					q.emplace(i);
					sign[i]=true;
				}
			} else if(dis[i]==dis[u]+1) {
				f[i]+=f[u];
				if(f[i]>2) {
					f[i]=3;
				}
			}
		}
	}
	for(int i=s; i<=n; i++) {
		if(f[i]==2) {
			++ans;
		}
	}
	return;
}
int main(void) {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	if(c<=6) {
		while(T--) {
			scanf("%d%lld",&n,&d);
			for(int i=1; i<=n; i++) {
				scanf("%lld",&x[i]);
			}
			ans=0;
			for(int i=n; i>=1; i--) {
				wrk1(i);
			}
			printf("%lld\n",ans);
		}
	} else {
		while(T--) {
			scanf("%d%lld",&n,&d);
			for(int i=1; i<=n; i++) {
				scanf("%lld",&x[i]);
			}
			ans=0;
			for(int i=1; i<=n; i++) {
				lim[i]=calc(i);
			}
			for(int i=n; i>=1; i--) {
				wrk2(i);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}
