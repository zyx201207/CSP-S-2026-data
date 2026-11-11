#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w,k[505],a,t,l,r,ans,books[10000505];
vector<int> ways[500005],times[500005];
void add(int x,int y,int s){
	ways[x].push_back(y);times[x].push_back(s);
	ways[y].push_back(x);times[y].push_back(s);
}
long long dfs(int x,int y,long long s){
	if(x == y){
		return s;
	}
	long long mmin = INT_MAX;
	for(int i = 0;i < ways[x].size();i++){
		if(!books[ways[x][i]]){
			books[x] = 1;
			mmin = min(mmin,dfs(ways[x][i],y,s + times[x][i]));
			books[x] = 0;
		}
	}
	return mmin;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w;
		add(i,i + m,w);
	}
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a >> t;
			add(a + m,2 * m + i,t);
		}
	}
	while(q--){
		ans = 0;
		cin >> l >> r;
		cout << dfs(l,r,0) << '\n';
	}
	return 0;
}
