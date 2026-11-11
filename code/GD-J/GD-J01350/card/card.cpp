#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
int a[200005];
int ans[N];
int vis[N];
int cards[N];
int cnt = 0;
int pre[N];
int main(){
	memset(vis,-1,sizeof(vis));
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("card4.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	bool flag = true;
	for(int i =  0; i < n; i++){
		cin >> a[i];
		if(a[i] < a[i-1]){
			flag = false;
		}
	}
	if(flag){
		int mp[100005];
		memset(mp,0,sizeof(mp));
		for(int i = 0; i < n; i++){
			mp[a[i]]++; 
		}
		for(int i = 1; i <= m; i++){
			mp[i] = mp[i-1] + mp[i];
		}
		for(int i = 1; i <= m; i++){
			cout << mp[i] << ' ';
		}
	}else{
		for(int i = 0; i < n; i++){
			memset(vis,-1,sizeof(vis));
			memset(cards,0,sizeof(cards));
			for(int j = i; j < n; j++){
				if(vis[a[j]] == -1){
					cards[cnt++] = a[j];
					vis[a[j]] = cnt-1;
				}else{
					int lastcnt = cnt;
					cnt = vis[a[j]] + 1;
					for(int k = cnt; k < lastcnt; k++){
						vis[cards[k]] = -1;
					}
				}
			}
			for(int j = 0; j < cnt; j++){
				ans[cards[j]]++;
			}
		}
		for(int i = 1; i <= m; i++){
			cout << ans[i] << ' ';
		}
	}
}
