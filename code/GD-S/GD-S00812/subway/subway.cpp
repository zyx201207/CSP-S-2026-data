#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =	2e5 + 5;
const int Q = 1e5 + 5;

int c;
ll n,m,d,q;
ll w[N];
struct Node{
	int x,y;
}r[Q];
int a[505][N];
ll t[505][N];
int fa[N];

int find(int x){
	if(fa[x] == x)  return x;
	return fa[x] = find(fa[x]);
}

void bulid(int x,int y){
	int fx = find(x);
	int fy = find(y);
	if(fx  != fy) fa[fy] = fx;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) fa[i] = i;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		int x;
		for(int j = 1;j <= k;j++){
			cin >> a[i][j];
			cin >>t[i][j];
			if(j == 1){
				x = a[i][j];
				continue;
			}
			bulid(x,a[i][j]);
		}
	}
	for(int i = 1;i <= q;i++) {
		cin >> r[i].x >> r[i].y;
		long long ans = w[r[i].x] + w[r[i].y];
		
		cout << ans << "\n";
	}
	
	
	return 0;
}
