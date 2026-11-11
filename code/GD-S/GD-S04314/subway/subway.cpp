#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
vector<int> a[505];
vector<int> s[505];//一个站被哪些线经过 
int t[505][505];
int vis[20005];
struct node{
	int stat,spnd,line;//station,spent_time
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			int x,y;
			cin >> x >> y;
			a[i].push_back(x);
			t[x][i] = y;
			s[x].push_back(i);
		}
	}
	while(q--){
		int start,final;
		cin >> start >> final;
		memset(vis,0x3f,sizeof(vis));
		int ans = 1e9;
		queue<node> q;
		for(int i : s[start]){
			q.push({start,w[start]+t[start][i],i});
		}
		vis[start] = true;
		while(!q.empty()){
			node cur = q.front();
			//cout << cur.stat << ' ' << cur.spnd << ' ' << cur.line << endl;
			q.pop();
			if(cur.stat == final){
				ans = min(ans,cur.spnd+w[final]+t[final][cur.line]);
			}
			for(int i : a[cur.line]){
				//cout << cur.stat << ' ' << i << endl;
				if(vis[i] <= cur.spnd){
					continue;
				}
				vis[i] = cur.spnd;
				if(s[i].size() == 1 || i == final){
					q.push({i,cur.spnd,cur.line});
				}else{
					q.push({i,cur.spnd,cur.line});
					for(int j : s[i]){
						//cout << '*' << i << ' ' << j << endl;
						int change = t[i][cur.line]+t[i][j];
						//cout<<'*'<<i<<' '<<cur.spnd+change<< ' '<<j<<endl;
						q.push({i,cur.spnd+change,j});
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
