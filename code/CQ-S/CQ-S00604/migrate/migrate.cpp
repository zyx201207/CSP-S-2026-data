#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
using pii=pair<int,ll>;
int cas,T,n; ll d,x[N];
vector<pii> e[N];
void dijkstra(){
	
}
void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	if(cas>=0&&cas<=10){
		for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++){
			int dis=x[j]-x[i];
			if(dis<=d)e[i].push_back({j,1});
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>cas>>T;
	while(T--)solve();
	return 0;
}

