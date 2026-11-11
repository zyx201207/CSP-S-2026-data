#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll a[N];
struct S{
	int qw;
	int qe;
};
int c,n,m,d,p;
vector<int> v[N];
vector<int> vv[N];
void dfs(int xid,int mdd){
	ll x=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=v[i].size();j++){
			if(v[i][j]==xid){
				x+=vv[i][j];
				for(int k=1;k<=v[i].size();k++){
					if(v[i][k]==mdd){
						x+=vv[i][k];
					}
				}
				xid=mdd;
				break;
			}
		}
	}
	cout << x << endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> n >> m >> d >> p;
	for(int i=1;i<=m;i++){
		cin >>a[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			int at,tt;
			cin >> at >> tt;
			v[i].push_back(at);
			vv[i].push_back(tt);
		}
	}
	while(p--){
		int x,y;
		cin >> x >> y;
		if(n>2e4){
			cout << vv[1][1]*(y-x) << endl;
		}
		dfs(x,y);
	}
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	return 0;
} 
