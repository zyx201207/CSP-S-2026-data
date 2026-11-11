#include <bits/stdc++.h>

int main(){
	std::freopen("subway.in","r",stdin);
	std::freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0),std::cout.tie(0);
	int c,n,m,d,q;
	std::cin>>c>>n>>m>>d>>q;
	std::vector<int> w(m+1);
	for (int i=1;i<=m;i++) std::cin>>w[i];
	int idx=1;
	std::vector<int> h(m+1,0);
	std::vector<int> vtex(1),nxt(1),wt(1);
	for (int i=1;i<=n;i++){
		int k;
		std::cin>>k;
		std::vector<int> a(k+1),t(k+1);
		for (int j=1;j<=k;j++) std::cin>>a[j]>>t[j];
		for (int j=1;j<=k;j++){
			for (int l=j+1;l<=k;l++){
				wt.push_back(t[j]+t[l]),vtex.push_back(a[l]),nxt.push_back(h[a[j]]),h[a[j]]=idx++;
				wt.push_back(t[l]+t[j]),vtex.push_back(a[j]),nxt.push_back(h[a[l]]),h[a[l]]=idx++;
			}
		}
	}
	while (q--){
		int x,y;
		std::cin>>x>>y;
		std::vector<long long> dis(m+1,1LL<<62);
		std::vector<bool> vis(m+1,false);
		std::priority_queue<std::pair<long long,int>,std::vector<std::pair<long long,int>>,std::greater<std::pair<long long,int>>> pq;
		dis[x]=0;
		pq.push({dis[x],x});
		while (!pq.empty()){
			int l=pq.top().second;
			pq.pop();
			if (vis[l]) continue;
			vis[l]=true;
			for (int p=h[l];p;p=nxt[p]){
				if (dis[vtex[p]]>dis[l]+wt[p]){
					dis[vtex[p]]=dis[l]+wt[p];
					pq.push({dis[vtex[p]],vtex[p]});
				}
			}
		}
		std::cout<<w[x]+dis[y]+w[y]<<"\n";
	}
	return 0;
}

