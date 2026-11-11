#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int c;//测试点编号 
	int n;//B市有多少条地铁线路 
	int m;//B市有多少个地铁站 
	int d;//每个地铁站最多有多少条线路经过
	int q;//出行计划数 
	long long ans; //最终答案 
	cin >> c >> n >> m >> d >> q;
	int w[500005];
	int k[505];
	int a[505][500005];
	int t[505][500005];
	int x[100005];
	int y[100005];
	for (int i = 1;i <= n;i++){
		cin >> k[i];
		for (int j = 1;j <= k[1];j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for (int i = 1;i <= q;i++){
		cin >> x[i] >> y[i];
	}
	for (int g = 1;g <= q;g++){
		ans = ans + w[x[g]] + w[y[g]];
		cout << ans;
	}
	return 0;
}
//Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?Oct31==Dec25?
