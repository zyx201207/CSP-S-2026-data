#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
const int N = 2001000;

int c,t,n,ans;
ll d,pos[N];

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while (t--) {
		memset(pos,0,sizeof(ll)*(n+3));
		ans = 0;
		scanf("%d%lld",&n,&d);
		for (int i = 1;i <= n;i++) scanf("%d",&pos[i]);
		for (int i = 1;i <= n;i++) {
			for (int j = i+3;j <= n;j++) {
				if (pos[j]-pos[i] > d*2) break;
				if (pos[j]-pos[i] <= d) continue;
				int cnt = 0;
				for (int k = i+1;k < j;k++) {
					if (pos[k]-pos[i] <= d && pos[j]-pos[k] <= d) cnt++;
					if (pos[k]-pos[i] > d && pos[j]-pos[k] <= d) break;
				}
				if (cnt == 2) ans++;
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
