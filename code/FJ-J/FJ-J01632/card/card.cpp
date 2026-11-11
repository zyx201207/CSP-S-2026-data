#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],rt[300005],vis[300005],cnt[300005];
vector<int> s[300005];
inline void f(int x){
	vis[x]=1;
	for(int y:s[x]){
		f(y);
		cnt[x]+=cnt[y];
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		rt[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		if(rt[i]==n) continue;
		s[a[rt[i]+1]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		cnt[a[i]]++;
	}
	f(a[n]);
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}

