#include<bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5,M = 3 * 1e5 + 5;
int n,m;
int a[N];
int ans[N];
int cnt[N];
int fi[N];
bool vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++){
		scanf("%d",&a[i]);
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++) cnt[j] = 0,fi[j] = n + 1;
		for(int j = i; j <= n; j++){
			if(fi[a[j]] == n + 1) fi[a[j]] = j;
			vis[j] = 0;
		}
		for(int j = i; j <= n; j++){
			cnt[a[j]]++;
			if(cnt[a[j]] >= 2){
				int firs = 0;
				for(int k = i; k <= n; k++){
					if(a[k] == a[j]){
						firs = k;
						break;
					}
				}
				for(int k = firs; k < j; k++){
					vis[k] = 1;
				}
				fi[a[j]] = j;
				cnt[a[j]] = 1;
			}
		}
		for(int j = i; j <= n; j++){
			if(vis[j] == 0) ans[a[j]]++;
		}
	}
	for(int i = 1; i <= m; i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
