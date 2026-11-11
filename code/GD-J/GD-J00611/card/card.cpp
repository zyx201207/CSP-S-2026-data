#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n,m,cnt,sum;
bool vis[N];
int a[N],ans[N],ip[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	for(int i = 1; i <= n; i++){
		int v[N];
		memset(vis,0,sizeof(vis));
		for(int j = i; j <= n; j++){
			if(vis[a[j]]){
				for(int k = ip[a[j]]; k <= cnt; k++)
					vis[v[k]] = 0;
				cnt = ip[a[j]];
			}
			v[++cnt] = a[j];
			ip[a[j]] = cnt;
			vis[a[j]] = 1;
		}
		for(int j = 1; j <= m; j++)
			if(vis[j])
				ans[j]++;
	}
	for(int i = 1; i <= m; i++)
		cout<<ans[i]<<' ';
	return 0;
}
