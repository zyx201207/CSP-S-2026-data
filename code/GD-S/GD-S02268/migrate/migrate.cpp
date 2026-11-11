#include <bits/stdc++.h>

long long x[2000001];

int main(){
	std::freopen("migrate.in","r",stdin);
	std::freopen("migrate.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0),std::cout.tie(0);
	int c,t;
	std::cin>>c>>t;
	while (t--){
		int n;
		long long d;
		std::cin>>n>>d;
		for (int i=1;i<=n;i++) std::cin>>x[i];
		int idx=1;
		std::vector<int> h(n+1,0);
		std::vector<int> vtex(1),nxt(1);
		for (int i=1;i<=n;i++){
			for (int j=std::lower_bound(x+1,x+n+1,x[i]-d)-x;j<=std::upper_bound(x+1,x+n+1,x[i]+d)-x-1;j++) vtex.push_back(j),nxt.push_back(h[i]),h[i]=idx++;
		}
		long long ans=0;
		for (int i=1;i<=n;i++){
			std::vector<int> dis(n+1,0x7fffffff),cnt(n+1,0);
			std::queue<int> q;
			dis[i]=0,cnt[i]=1;
			q.push(i);
			while (!q.empty()){
				int l=q.front();
				q.pop();
				for (int p=h[l];p;p=nxt[p]){
					if (dis[vtex[p]]>dis[l]+1){
						dis[vtex[p]]=dis[l]+1,cnt[vtex[p]]=1;
						q.push(vtex[p]);
					}else if (dis[vtex[p]]==dis[l]+1) cnt[vtex[p]]+=cnt[l];
				}
			}
			for (int j=i+1;j<=n;j++){
				if (cnt[j]==2) ans++;
			}
		}
		std::cout<<ans<<"\n";
	}
	return 0;
}

