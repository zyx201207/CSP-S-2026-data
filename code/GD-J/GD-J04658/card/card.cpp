#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[500005],ans[300005],fa[500005],lst[300005],sz[500005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
	}
	for(int i=n;i>=1;i--) {
		if(!lst[a[i]]) {
			fa[i]=i;
		}
		else {
			fa[i]=lst[a[i]];
		}
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++) {
		sz[i]++;
		if(fa[i]==i) {
			ans[a[i]]+=sz[i];
			sz[i+1]+=sz[i];
		}
		else {
			sz[fa[i]]+=sz[i];
		}
	}
	for(int i=1;i<=m;i++) {
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}
