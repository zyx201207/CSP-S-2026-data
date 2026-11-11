#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5,M = 3e5+5;
int n,m,a[N],ans[M],s[M];
bool vis[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
		s[a[i]]++;
	}
	int cnt = 0;
	for (int i = n;i>=1;i--){
		cnt = 0;
		while (!vis[a[i-cnt]] && i-cnt>=1){
			cnt++;
			ans[a[i]]++;
		}
		vis[a[i]] = true;
	}
	ans[a[n]] = n;
	for (int i = 1;i<=m;i++){
		printf("%d ",max(ans[i],s[i]));
	}
	return 0;
}

