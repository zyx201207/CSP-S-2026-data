//GZ-S00371
//遵义市新蒲新区滨湖中学
//邓佳琪 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	
	int c, n, m, d, p;
	cin >> c >> n >> m >> d >> p;
	struct line{
		int t[100000];
	};

	int w[m + 1];
	for (int i = 1;i <= m;i ++) cin >> w[i];	
	line li[n + 1];
	for (int i = 1;i <= n;i ++){
		int k;
		cin >> k;
		for (int j = 1;j <= m ;j ++){
			li[i].t[j] = 1e9;
		}
		for (int j = 1;j <= k; j ++){
			int q, e;
			cin >> q >> e;
			li[j].t[q] = e;
		}
			
	}
	
	while(p --){
		int be, en;
		cin >> be >> en;
		int ans = w[en];
		
		int x;
		while (x != be){
			int mn = 1e9;
			int l;
			for (int i = 1;i <= n;i ++){
				if (li[i].t[x] < mn){
					l = i;
					mn = li[i].t[x];
				}
			}			
			ans += mn;
			for (int i = 1;i < x;i ++){
				if (li[l].t[i] != 1e9){
					x = i;
					ans += li[l].t[i];
				}
			}
		}		
		ans += w[x];
		cout << ans << endl;
	}
	
/*	while(q--)
{
	int be, en;
	cin >> be >> en;
	int d1[m + 1]; for(int i = 1;i <= m; i ++) d1[i] = 1e7;
	int d2[m + 1]; for(int i = 1;i <= m; i ++) d2[i] = 1e7;
	dist_line d3[n + 1];
	for (int i = 1;i <= n;i ++){
		for (int j = 1;j <= k ; j ++){
			line[i].d[j] = 1e7;
		}	  
	}
	queue<pair<int, int> q;
	q.push{1, be};
	while(!q.empty()){
		int x = q.front.first, y = q.front.second;
		q.pop();
		if (x == 1){
			
		}
	}		
	
}	*/
	return 0;
}






