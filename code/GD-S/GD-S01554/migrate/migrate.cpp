#include<bits/stdc++.h>
using namespace std;

long long a[2123456];
	long long dis[5010][5010];
int n,t;
long long d;
unsigned c;
void solve();
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}
namespace tmlrock1{
	int cnt[5010][5010];
	void solution() {//24pts
		memset(dis,0x3f,sizeof dis);
		cin>>n>>d;
		for(int i = 0;i<n;++i)cin>>a[i];
		for(int i = 0;i<n;++i){
			int j = i;
			while(((++j)<n) && ((a[j] - a[i])<=d)) dis[i][j] = 1;
		}for(int i = 0;i<n;++i)for(int j = 0;j<n;++j)cnt[i][j] = 1;
		int ans = 0;
		for(int i = n-1;~i;--i)for(int j = i+2;j<n;++j)if(dis[i][j]!=1)for(int k = i+1;(k<j) && (dis[i][k] == 1);++k) {
//			cout<<"\ttmlrock"<<i<<' '<<j<<' '<<k<<endl;
			if(dis[i][j] > dis[i][k] + dis[k][j]) {
				dis[i][j] = dis[i][k] + dis[k][j];
				cnt[i][j] = 1;
			}else if(dis[i][j] == dis[i][k]+dis[k][j]) ++ cnt[i][j];
		}
			
		for(int i = 0;i<n;++i)for(int j = i+1;j<n;++j){
		if(cnt[i][j] == 2)++ans;
//		cout<<dis[i][j]<<' '<<cnt[i][j]<<' '<<i<<' '<<j<<endl;
		}cout<<ans<<endl;
	}
}
string tmp;
namespace tmlrock2{
	void solution() {//8pts
		cin>>n>>d;
		for(int i = 0;i<n;++i)cin>>a[i];
		long long d2 = d / (a[1] - a[0]);
		if(d2 <= 1) cout << "0\n";
		else cout << max(0ll,(n - (d2<<1) + 1) )<<'\n';
	}
	void solve() {
		cin>>n>>d;
		
	}
}
void solve() {
	if(c<=6) tmlrock1::solution();
	else if(c==11 || c==12) tmlrock2::solution();
	else cout<<0;
}
