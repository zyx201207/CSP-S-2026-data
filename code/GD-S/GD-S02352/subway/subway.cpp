#include<bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
int c,n,m,d,q;
struct station{
	vector<pair<int,int>> lines;
}a[500005];
int l[505];
int w[505];
int mp[505][505];
void floyed(){
	for(int i =1;i <= n ;++i ){
		for(int j = 1;j <= n;++j){
			for(int k = 1;k <= n;++k){
				mp[i][j] = min(mp[i][j],mp[i][k]+mp[k][j]);
			}
		}
	}
}
void mk(int e){
	for(int i = 0;i < a[e].lines.size();++i){
		for(int j = 0;j < a[e].lines.size();++j){
			mp[a[e].lines[i].x][a[e].lines[j].x] = min(mp[a[e].lines[i].x][a[e].lines[j].x], a[e].lines[i].y + a[e].lines[j].y);
		}
	}
}
int dis(int st,int en){
	int mn = INT_MAX + 0LL;
//	cout << a[st].lines.size() <<a[en].lines.size();
	for(int i = 0;i < a[st].lines.size();++i){
		for(int j = 0;j < a[en].lines.size();++j){
			mn = min(mn,mp[a[st].lines[i].x][a[en].lines[j].x] + a[st].lines[i].y + a[en].lines[j].y);
//	cout << mn << ' ';
		}
	}
	return mn + w[st] + w[en];
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0),cout.tie(0);
	scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
	for(int i = 1; i <= m ;++i ){
		scanf("%lld",&w[i]);
	}
	for(int i =1;i <= n ;++i ){
		for(int j = 1;j <= n ;++j){
			mp[i][j] = INT_MAX + 0LL;
		}
	}
	for(int i =1;i <= n ;++i ){
		mp[i][i] = 0;
	}
	for(int i =1;i <= n ;++i){
		scanf("%lld",&l[i]);
		for(int j =1;j <= l[i] ;++j ){
			pair<int,int> t;
			int q;
			scanf("%lld %lld",&q,&t.y);
			t.x = i;
			a[q].lines.push_back(t);
		}
	}
	for(int i = 1;i <= m;++i){
		mk(i);
	}//O(md^2)
//	for(int i =1;i <= n ;i ++){
//		for(int j = 1;j <= n ;j++){
//			cout << mp[i][j];
//		}
//		cout << endl;
//	}
	floyed();//O(n^3)
	++q;
	while(--q){
		int st,en;
		scanf("%lld %lld",&st,&en);
		printf("%lld\n",dis(st,en));
	}
	fclose(stdin);
	fclose(stdout);
}
