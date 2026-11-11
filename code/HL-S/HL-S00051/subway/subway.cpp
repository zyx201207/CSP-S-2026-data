#include<bits/stdc++.h>
using namespace std;
const int N = 505,M = 5e3 + 5;
int text,n,m,d,q,w[M],a[M][M],num = 0,b[M],c[M];
bool vis[N];
vector<int> e[M];
void init(){
	for(int i = 1;i <= n;i++) vis[i] = 0;
}
int slove(int x,int y){
	/*int ans = 0;
	for(int now = 0,i = e[x][now];i != 0;now++){
		if(vis[i]) continue;
		vis[i] = true;
		ans = max(ans,slove(i,y) + a[x][i]);
	}
	return ans;
	*/
	//写不出来了qwq 
}
int main(){
	freopen("subway.in ","r",stdin);
	freopen("subway.out ","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin >> text >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> num;
		for(int j = 1;j <= num;j++){
			cin >> b[j] >> c[j];
		}
		for(int j = 1;j < num;j++){
			for(int k = j + 1;k <= num;k++){
				e[b[j]].push_back(b[k]);
				e[b[k]].push_back(b[j]);
				a[b[j]][b[k]]=max(a[b[j]][b[k]],c[j]+c[k]);
				a[b[k]][b[j]]=max(a[b[k]][b[j]],c[j]+c[k]);
			}
		}
	}
	for(int i = 1;i <= q;i++){
		init();
		int x,y;
		cin >> x >> y;
		cout << slove(x,y) + w[x] + w[y] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
