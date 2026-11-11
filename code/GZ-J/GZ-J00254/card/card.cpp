//GZ-J00254 遵义市新蒲新区白鹭湖小学 韩定远
#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5;
long long a[N];
long long cnt[N];
vector<long long> vis(N);
long long n, m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld", &n, &m);
	for (long long i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	for (long long i = 1; i <= n; i++){
		for (long long j = i; j <= n; j++){
			if (!vis[a[j]]) {
				for (long long k = vis[a[j]]; k <= vis.size(); k++){
					vis.erase(k);
				}
			} else vis[a[j]] = j;
		}
	}
	for (long long i = 1; i <= n; i++){
		printf("%lld ", cnt[i]);
	}
	fclose(stdin);
	fclose(stdout);
}

