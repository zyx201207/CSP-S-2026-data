#include<iostream>
#include<vector>
#include<utility>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=5e2+10,M=5e5+10;
using pii=pair<int,int>;
int c,n,m,d,q,w[M];
vector<pii> ids[M];
using ll=long long;
ll tds[N][N],rel;
const ll linf=1e18;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)memset(tds[i]+1,0x3f,n<<3),tds[i][i]=0;
	for(int i=1,tk;i<=n;i++){
		cin>>tk;
		for(int l=1,ta,tt;l<=tk;l++){
			cin>>ta>>tt;
			ids[ta].emplace_back(i,tt);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0,td1,td2;j<ids[i].size();j++){
			td1=ids[i][j].first;
			for(int l=j+1;l<ids[i].size();l++){
				td2=ids[i][l].first;
				// cout<<td1<<' '<<td2<<' '<<ids[i][j].second<<' '<<ids[i][l].second<<'\n';
				tds[td1][td2]=min<ll>(tds[td1][td2],ids[i][j].second+ids[i][l].second);
				tds[td2][td1]=min<ll>(tds[td2][td1],ids[i][j].second+ids[i][l].second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				tds[j][l]=min(tds[j][l],tds[j][i]+tds[i][l]);
			}
		}
	}
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=n;j++)cout<<tds[i][j]<<" \n"[j==n];
	// }
	for(int i=1,tx1,tx2;i<=q;i++){
		rel=linf;
		cin>>tx1>>tx2;
		if(tx1==tx2){
			cout<<0<<'\n';
			continue;
		}
		for(auto& j:ids[tx1]){
			for(auto& l:ids[tx2]){
				rel=min(rel,tds[j.first][l.first]+j.second+l.second);
			}
		}
		rel+=w[tx1]+w[tx2];
		cout<<rel<<'\n';
	}
}