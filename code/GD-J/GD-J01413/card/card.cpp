#include <bits/stdc++.h>
using namespace std;

int n,m,a[500005],ans[500005],la[500005],s[500005];
bool vis[500005];

int main () {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++) {
		scanf("%d",&a[i]);
		la[a[i]] = i;
		s[a[i]]++;
	}
	for (int i = 1,pos;i <= n;i++) {
		if (vis[a[i]]) continue;
		vis[a[i]] = 1;
		pos = i;
		while (pos <= n) {
			ans[a[pos]] += s[a[i]];
			pos = la[a[pos]] + 1;
		}
	}
	for (int i = 1;i <= m;i++) printf("%d ",ans[i]);
	printf("\n"); 
	return 0;
}
