#include<iostream>
#include<vector>
using namespace std;
const int MAXM = 5e5 + 5,MAXN = 505;
int c,n,m,d,q;
long long w[MAXM],dis[MAXN][MAXN];
struct zd{
	int a,t; 
};
struct rd{
	int v,w;
};
struct js{
	int wzz,q;
};
vector <zd> r[MAXN];
vector <rd> b[MAXN];
vector <js> wz[MAXM];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			int x,y;
			cin >> x >> y;
			r[i].push_back({x,y});
		}
	}for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			bool flag = 1;
			int minn = 0;
			dis[i][j] = 9e12;
			dis[j][i] = 9e12;
			//cout << dis[i][j] << endl;
			for(int k1 = 0;k1 < r[i].size();k1++){
				if(i == 1) wz[r[i][k1].a].push_back({i,r[i][k1].t});
				for(int k2 = 0;k2 < r[j].size();k2++){
					if(i == 1 && k1 == 0) wz[r[j][k2].a].push_back({j,r[j][k2].t});
					int x1 = r[i][k1].a,x2 = r[j][k2].a;
					int x = r[i][k1].t+ r[j][k2].t;
					//cout << r[i][k1].a << " " << r[j][k2].a << endl;
					if(x1 == x2){
						if(flag){
							 minn = x;
							 flag = 0;
						}
						minn = min(minn,x);
					}
				}
			}
			if(!flag){
				dis[i][j] = minn;
				dis[j][i] = minn;
			}
		}	
	}
	for(int i = 1;i <= n;i++){
		for(int j = i + 1;j <= n;j++){
			for(int k = 1;k <= n;k++){
				if(k == i || k == j) continue;
				dis[i][j] = min(dis[i][k] + dis[k][j],dis[i][j]);
				dis[j][i] = dis[i][j];
			}
			//cout << i << " " << j << " " << dis[i][j] << endl; 
		}
		
	}
//	cout<<"------------------"<<endl;
//	for(int i = 1;i <= 5;i++){
//		for(int j = 0;j < wz[i].size();j++){
//			cout << i << " " << wz[i][j] << endl;
//		}
//	}
	for(int i = 1;i <= q;i++){
		int x,y;
		long long ans;
		cin >> x >> y;
		for(int i = 0;i < wz[x].size();i++){
			//cout <<  wz[x][i] << endl;
			for(int j = 0;j < wz[y].size();j++){
				int x1 = wz[x][i].wzz,x2 = wz[x][i].q,y1 = wz[y][j].wzz,y2 = wz[y][j].q;
				if(i == 0 && j == 0) ans = dis[x1][y1] + x2 + y2;
				ans = min(dis[x1][y1] + x2 + y2,ans);
				//cout << y1 << " " << dis[x1][y1] + x2 + y2<<" " << ans << endl;
			}
		}
		ans = ans + w[x] + w[y];
		printf("%lld\n",ans);
	}
	

	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 8 100 4 6 6 7
1 6
2 3
*/

