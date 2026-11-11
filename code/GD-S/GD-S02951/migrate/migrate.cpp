#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int n,d;
int a[N];
bool f[N];
int dfs(int s,int e) {
	if(a[e]-a[s]<=d)return 1;
	if(s+1==e)return a[e]-a[s]<=d;
	int ans=0;
	for(int i=s+1; i<e; i++) {
		if(a[i]-a[s]<=d)ans+=dfs(i,e);
		if(ans>2)return -1e9;
	}
	return ans;
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c, _=1;
	scanf("%d%d",&c,&_);
	while(_--) {
		scanf("%d%d",&n,&d);
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
			if(i>1) {
				if(a[i]-a[i-1]>d)f[i-1]=0;
			}
		}
		int cnt=0;
		for(int i=1; i<=n; i++) {
			if(f[i])continue;
			for(int j=i+2; j<=n; j++) {
				if(f[j-1])continue;
				int s=dfs(i,j);
				if(dfs(i,j)==2)cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
