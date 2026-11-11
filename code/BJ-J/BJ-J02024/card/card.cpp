#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n,m,a[N],ans[N];
bool vis[N];
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++){
		memset(vis,0,sizeof(vis));
		for(int j = i;j <= n;j++)
			vis[a[j]] = 1;
		for(int i = 1;i <= m;i++)
            if(vis[i]) ans[i]++;
	}
	for(int i = 1;i <= m;i++) cout << ans[i] << ' ';
	return 0;
}
