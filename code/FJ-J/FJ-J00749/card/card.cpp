#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
int n,m,a[maxn],nxt[maxn],cnt[maxn];
signed main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	unordered_map<int,int> lst;
	for(int i = n;i >= 1;--i) {
		if(lst.count(a[i])) nxt[i] = lst[a[i]];
		else {
			nxt[i] = -1;
			lst[a[i]] = i;
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = i;j <= n;j++) {
			while(nxt[j]!=-1) j = nxt[j];
			cnt[a[j]]++;
		}
	}for(int i = 1;i <= m;i++) cout<<cnt[i]<<' ';
	return 0;
} 
