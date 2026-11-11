#include<bits/stdc++.h>
using namespace std;
int la[500005],ans[300005],a[500005],vis[500005];
vector <int> g[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	//freopen("card.out","w",stdout);
	//printf("%d %d",1,1);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= n;i++)
		la[a[i]] = i;
	for (int i = n;i >= 1;i--){
		int j = i;
		///printf("%d %d",1,1);
		while(j <= n){
			if(vis[j]){
				for (int k = 0;k < g[j].size();k++)
					ans[g[j][k]]++,g[i].push_back(g[j][k]);
				break;
			}
			g[i].push_back(a[j]);
			ans[a[j]]++,j = la[a[j]] + 1;
		}
		vis[i] = 1;
	}
	for (int i = 1;i <= m;i++){
		if(a[n] == i) printf("%d ",n);
		else printf("%d ",ans[i]);
	}
	return 0;
}
