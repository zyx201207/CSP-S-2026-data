#include<iostream>
using namespace std;
long long a[2000010];
pair<int, int>vis[2000010];
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	scanf("%d%d", &c, &t);
	while(t--){
		int n;long long d, ans=0;
		scanf("%d%lld", &n, &d);
		for(int i=1;i<=n;i++)scanf("%lld", &a[i]);
		if(n==1){
			printf("0\n");
			continue;
		}
		if(c==11||c==12){
			long long t=max(d/(a[2]-a[1]), 1ll);
			for(int i=1;i<=n;i++)ans+=(n-i)/t;
			printf("%lld\n", 1ll*n*(n-1)/2-ans);
			continue;
		}
		for(int i=1;i<n;i++){
			vis[i]={0, 1};
			for(int j=i+1;j<=n;j++){
				vis[j]={1e9, 0};
				for(int k=j-1;k>=i&&a[j]-a[k]<=d;k--)if(vis[j].first>vis[k].first+1)vis[j]={vis[k].first+1, vis[k].second};
				else vis[j].second=min(vis[j].second+vis[k].second, 3);
				if(vis[j].second==2)ans++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
