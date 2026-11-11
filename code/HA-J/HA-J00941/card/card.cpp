#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 +10;

int a[N], fa[N], last[N], sz[N];
int n, m;
ll ans[N];


int find(int x){
	if(fa[x] == x)return x;
	else return fa[x] = find(fa[x]);
}

void merge(int x, int y){
	int tx = find(x), ty = find(y);
	if(tx != ty){
		fa[tx] = ty;
		sz[ty] += sz[tx];
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		fa[i] = i;
		sz[i] = 1;
	}
	
	for(int i = n; i >= 1; i--){
		if(last[a[i]]){
			merge(i, last[a[i]]);
		}
		last[a[i]] = i;
	}
	
	for(int i = 1; i < n; i++){
		if(fa[i] == i){
			ans[a[i]] += sz[i];
			merge(i, i + 1);
		}
	}
	ans[a[n]] += n;
	for(int i = 1; i <= m; i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
