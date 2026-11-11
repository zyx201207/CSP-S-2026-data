#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
int n,m;
vector<int> q[3002];
int cpt[3002];
int a[200002],ans[3002];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		q[a[i]].push_back(i);
	}
	for (int i = 1;i <= n;i++){
		int vis[3002] = {};
		for (int j = i;j <= n;j++){
			if (q[a[j]][q[a[j]].size() - 1] > j){
				j = q[a[j]][q[a[j]].size() - 1];
			}
			vis[a[j]] = 1;
		}
		for (int j = 1;j <= m;j++){
			ans[j] += vis[j];
			vis[j] = 0;
		}
	}
	for (int i = 1;i <= m;i++){
		printf("%d ",ans[i]);
	}
}
