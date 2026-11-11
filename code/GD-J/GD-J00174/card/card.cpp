#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],vis[N],ans[N],cnt[N];
vector<int>G[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		vis[a[i]]=i;
	}
	for (int i=1;i<=n;i++){
		if (cnt[a[i]]){
			for (auto j:G[a[i]]){
				if (j>=i)ans[a[j]]++;
			}
		}
		else{
			cnt[a[i]]=1;
			for (int j=i;j<=n;j++){
				G[a[i]].push_back(vis[a[j]]);
				ans[a[j]]++;
				j=vis[a[j]];
			}
		}
	}
	for (int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
