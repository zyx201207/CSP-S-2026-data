//GZ-S00288 贵阳市南明区华麟学校 徐文景 
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500+10,M=5e5+10;
int c,n,m,d,q,k,v,t,x,y,v1,t1,sumn;
int w[M],fa[M];
struct p{
	int v,t;
};
vector<p> road1[N];
vector<int> cross[M];
vector<p> road[N];
vector<int> hc[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		cin >> k;
		for(int j=1;j<=k;j++){
			cin >> v >> t;
			road[i].push_back({v,t});
			cross[v].push_back(i);
		}
	}
	for(int i=1;i<=m;i++){
		if(cross[i].size()>1){
			for(int st:cross[i]){
				for(int nd:cross[i]){
					if(st!=nd){
						hc[st][nd].push_back(i);
						hc[nd][st].push_back(i);
					}
				}
			}
		}
	}
	while(q--){
		cin >> x >> y;
		if(cross[x][0]==cross[y][0]){
			int temp=w[x]+w[y];
			bool fv=0;
			for(int ridx:cross[x]){
				for(p rc:road[ridx]){
					if(rc.v==x){
						temp+=rc.t;
						fv=1;
						break;
					}
				}
				if(fv) break;
			}
			fv=0;
			for(int ridx:cross[y]){
				for(p rc:road[ridx]){
					if(rc.v==y){
						temp+=rc.t;
						fv=1;
						break;
					}
				}
				if(fv) break;
			}
			cout << temp << "\n";
		}
	}
	return 0;
} 
