#include <iostream>
#include <vector>
#include <queue>

int main() {
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

	int n,m;
	scanf("%d%d",&n,&m);

	std::vector<int>a(n);

	for(auto &x:a)
		scanf("%d",&x);

	std::vector<int>sum(m+1);

	for(int i=0; i<(int)a.size(); ++i) {
		std::deque<int>dq;
		std::vector<bool>vis(m+1,false);

		for(int j=i; j<(int)a.size(); ++j) {
			if(!vis[a[j]]) {
				vis[a[j]]=true;
				dq.push_back(a[j]);
			} else {
				while(dq.back()!=a[j]) {
					vis[dq.back()]=false;
					dq.pop_back();
				}
			}
		}

		for(auto x:dq)
			sum[x]++;
	}

	for(int i=1; i<=m; ++i)
		printf("%d ",sum[i]);
	return 0;
}

/*
Input:
4 3
1 2 1 3
Input:
10 3
3 1 2 1 3 2 3 1 2 1
*/
