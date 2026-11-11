#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i = a; i <= b; i++)
#define bep(i,a,b) for(int i = a; i >= b; i--)
const int N = 5e5+10;
using namespace std;
int w[N];
vector<pair<int,int>>g[N];
int st[1002][1002],dis[1002][1002];
int t[20][10];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c, n, m, d,q;
	cin >> c >> n >> m >> d >> q;
	if(c>=7 && c <= 11){
		rep(i,1,m)rep(j,1,m)st[i][j]=1e18;
		rep(i,1,m)rep(j,1,m)dis[i][j]=1e18;
		rep(i,1,m)cin >> w[i];
		rep(i,1,n){
			int x,sta,ti1,ena,ti2;
			cin >> x >> sta >>ti1 >>ena >>ti2;
//			g[sta].push_back({ti1+ti2,ena});
//			g[ena].push_back({}) 
			st[sta][ena]=st[ena][sta]=min(ti1+ti2,st[sta][ena]);
			dis[sta][ena] = dis[ena][sta]=st[sta][ena];
		}
		rep(k,1,m){
			rep(i,1,m){
				if(i == k)continue;
				rep(j,1,m){
					if(i == j || k == j)continue;
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		rep(i,1,q){
			int x,y;
			cin >> x >>y;
			cout <<dis[x][y]+w[x]+w[y] <<"\n";
		}
	}else if(m <= 12){
		rep(i,1,m)cin >> w[i];
		rep(i,1,n){
			int x;
			cin >> x;
			rep(j,1,x){
				int y,z;
				cin >> y >> z;
				t[y][i]=z;
			}
		}	
		while(q--){
			int x,y;
			cin >> x >> y;
			int flag = 0;
			int ggmx=1e10;
			rep(i,1,3){
				if(t[x][i] && t[y][i]){
					cout << w[x]+w[y]+t[x][i]+t[y][i] <<"\n";
					flag = 1;
					break;
				}
			}
			if(!flag){
				int mi = 1e10;
				rep(i,1,m){
					if(i == x || i == y)continue;
					int flag1=0,flag2=0;
					rep(j,1,3){
						if(t[i][j] && t[x][j])flag1=j;
					}
					rep(j,1,3){
						if(t[i][j] && t[y][j])flag2=j;
					}
					if(flag1 && flag2){
						mi = min(mi, w[x]+w[y]+t[x][flag1]+t[i][flag1]+t[i][flag2]+t[y][flag2]);
					}
				}
				rep(i,1,m){
					rep(j,1,m){
						if(i == j)continue;
						if(i == x || i == y || j == x || j == y)continue;
						int flag1 = 0,flag2=0,flag3=0;
						rep(k,1,3){
							if(t[i][k] && t[x][k])flag1=k;
						}
						rep(k,1,3){
							if(t[i][k] && t[j][k])flag2=k;
						}
						rep(k,1,3){
							if(t[j][k] && t[y][k])flag3=k;
						}
						if(flag1 && flag2 && flag3){
							mi = min(mi, w[x]+w[y]+t[x][flag1]+t[i][flag1]+t[i][flag2]+t[j][flag2]+t[j][flag3]+t[y][flag3]);
						}
					}
				}
				cout <<mi <<"\n";
			}
		}
	}
	return 0;
}
