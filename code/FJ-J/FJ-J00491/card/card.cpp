#include <bits/stdc++.h>
using namespace std;
int a[500005],c[300005],cnt[300005];
bool vis[300005];
queue<int> q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(n == m){
		for(int i = 1; i <= n; i++){
			cout << i << " ";
		}
		return 0;
	}
	for(int i = 1; i <= n; i++){
		memset(vis,0,sizeof(vis));
		memset(c,0,sizeof(c));
		for(int j = i; j <= n; j++){
			if(vis[a[j]] == 1){
				for(int x = c[a[j]]+1; x < j; x++){
					vis[x]=0;
					c[x]=0;
				}
			} 
			vis[a[j]] = 1;
		}
		for(int j = 1; j <= m; j++){
			if(vis[j] != 0) cnt[j]++;
		}
	}
	for(int i = 1; i <= m; i++){
		cout << cnt[i] << " ";
	}
	return 0;
}
