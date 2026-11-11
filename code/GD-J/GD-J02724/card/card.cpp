#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n,m;

int now[N];
int ans[N];
int a[N];
int cnt[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i ++){
		for(int j = i;j <= n;j ++){
			if(cnt[a[j]] == 0){
				cnt[a[j]] ++;
				now[a[j]] = j;
			}
			else{
				for(int k = now[a[j]];k < j;k ++){
					cnt[a[k]] --;
				}
				cnt[a[j]] ++;
				now[a[j]] = j;
			}
		}
		for(int j = 1;j <= m;j ++){
			if(cnt[j]) ans[j] ++;
			cnt[j] = 0;
			now[a[j]] = 0;
		}
	}
	for(int i = 1;i <= m;i ++) cout << ans[i] << ' ';
	return 0;
}
/*
4 3
1 2 1 3
*/
