#include<bits/stdc++.h>
using namespace std;
int a[500005];
int st[500005], top;
int ans[300005];
int cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m; scanf("%d%d",&n,&m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++){
		top = 1;
		memset(st, 0, sizeof st);
		memset(cnt, 0, sizeof cnt);
		for(int j = i; j <= n; j++){
			if(cnt[a[j]]){
				int pre = top;
				top = cnt[a[j]] + 1;
				for(int k = cnt[a[j]] + 1; k <= pre; k++){
					cnt[st[k]] = 0;
					st[k] = 0;
				}
			}
			else{
				cnt[a[j]] = top;
				st[top++] = a[j];
			}
		}
		for(int j = 1; j < top; j++){
			ans[st[j]]++;
		}
	}
	for(int i = 1; i <= m; i++){
		cout << ans[i] << " ";
	}
	return 0;
}
