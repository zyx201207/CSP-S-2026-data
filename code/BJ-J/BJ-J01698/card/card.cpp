#include<bits/stdc++.h>
using namespace std;
int n,m,a[5000001],game[5000001],ans[5000001];
bool vis[5000001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>> n >> m;
	for(int i = 1;i <= n;i ++){
		cin>> a[i];
	}
	for(int i = 1;i <= n;i ++){
		int cnt = 0;
		for(int j = 1;j <= n;j ++){
			vis[j] = false;
		}
		for(int j = i;j <= n;j ++){
			if(vis[a[j]] != true){
				vis[a[j]] = true;
				game[++cnt] = a[j];
			}else{
				for(int k = 1; k <= cnt;k ++){
					if(game[k] == a[j]){
						cnt = k;
						break;
					}
				}
				for(int k = cnt; k <= n;k ++){
					game[k] = 0;
					vis[game[k]] = false;
				}
				vis[a[j]] = true;
				game[cnt] = a[j];
			}
		}
		for(int j = 1;j <= cnt;j ++){
			ans[game[j]]++;
		}
	}
	for(int i = 1;i <= m;i ++){
		cout<< ans[i] << ' ';
	}
	return 0;
}
