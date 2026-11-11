#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int>pa;
const int N=5e5+10;
const int M=510;
const ll inf=1e18;
int n,m,d,c,q;
ll w[N],mp[M][M];
vector<pa> p[N];//1->t,2->ÌØÅú 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++)cin >> w[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)mp[i][j]=0;
			else mp[i][j]=inf;
		}
	}
	for(int i=1,k;i<=n;i++){
		cin >> k;
		int tp=i;
		for(int j=1;j<=k;j++){
			ll a,t;
			cin >> a >> t;
			for(int i=0;i<p[a].size();i++){
				ll bt=p[a][i].first,b=p[a][i].second;
				mp[tp][b]=t+bt;
				mp[b][tp]=t+bt;
			}
			p[a].push_back({t,tp});
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]); 
			}
		}
	}
	for(int i=1,st,ed;i<=q;i++){
		cin >> st >> ed;
		ll tmp=inf;
		for(int j=0;j<p[st].size();j++){
			bool ok=0;
			for(int k=0;k<p[ed].size();k++){
				ll pst_v=p[st][j].first,ped_v=p[ed][k].first;
				int pst=p[st][j].second,ped=p[ed][k].second;
				tmp=min(tmp,pst_v+ped_v+mp[pst][ped]);
			}
			if(ok)break;
		}
		cout << w[st]+w[ed]+tmp << '\n';
	}
	return 0;
}
/*0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3*/
