#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int n,m;
int a[5*N];
int vis[3*N];
int c[5*N];
bool f1[3*N];
int ans[3*N];
signed main() {
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool f=1;
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		if(i>1&&a[i]<a[i-1])f=0;
	}
	if(m==1) {
		printf("%d",n);
		return 0;
	}
	if(m==2) {
		int s1=0,s2=0;
		for(int i=n; i>=1; i--) {
			if(a[i]==1&&s1==0)s1=i;
			if(a[i]==2&&s2==0)s2=i;
		}
		printf("%d %d",s1,s2);
	} else if(f) {
		int cnt[3*n];
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=n;i++){
			cnt[a[i]]=max(cnt[a[i]],i);
		}
		for(int i=1;i<=m;i++){
			printf("%d ",cnt[i]);
		}
	} else if(n<=5000) {
		for(int i=1; i<=n; i++) {
			memset(vis,0,sizeof vis);
			memset(c,0,sizeof c);
			memset(f1,0,sizeof f1);
			for(int j=i; j<=n; j++) {
				if(vis[a[j]]) {
					c[vis[a[j]]+1]++;
					c[j]--;
				}
				vis[a[j]]=j;
			}
			for(int j=i; j<=n; j++) {
				c[j]+=c[j-1];
				if(!f1[a[j]]&&c[j]==0) {
					f1[a[j]]=1;
					ans[a[j]]++;
				}
			}
		}
		for(int i=1; i<=m; i++) {
			printf("%d ",ans[i]);
		}
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
/*
4 3
1 2 1 3
*/
