#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
int w[500006];
struct station{
	int to[250];
	int h;
	int line[250];
}st[500006];
int ans;
int k[500006];
int a[5006][5006];
int t[5006][500];
void dfs(int x,int y,int tt,int cs = 1){ 
	if(x == y || cs > 10){
		if(tt > ans) ans = tt;
		return; 
	}
	while(st[x].h == 1){
		x = st[x].to[1];
		if(x == y){
			if(tt > ans) ans = tt;
			return; 
		}
	}
	for(int i = 1; i <= st[x].h; i++){
		int tttm = tt + t[x][st[x].line[i]];
		dfs(st[x].to[i],y,tttm,cs + 1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway1.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c>>n>>m>>d>>q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < k[i]; j++){
			st[a[i][j]].to[++st[a[i][j]].h]= a[i][j + 1];
			st[a[i][j]].line[st[a[i][j]].h] = i;
		}
		st[a[i][k[i]]].line[st[a[i][k[i]]].h] = k[i];
	}
	for(int i = 1; i <= q; i++){
		ll x,y;
		cin >> x >> y;
		dfs(x,y,w[x] + t[x][1]);
		cout << ans<<endl;
	}
	return 0;
}
