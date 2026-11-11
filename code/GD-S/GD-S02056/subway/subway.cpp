#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int MAXN = 505;
const int MAXM = 600000;


int c,n,m,d,q;

int bmap[MAXN][MAXN];


int w[MAXM];

int a[MAXN],t[MAXN];
bool visited[MAXN];

ll kru1(int rfrom, int rto, ll ans){
	if(rfrom == rto){
		return ans;
	}
	ll k = INT_MAX;
	for(int i=1;i<=m;i++){
		if(!visited[i]){
			visited[i] = true;
			k = min(k,kru1(i,rto,ans + bmap[rfrom][i]));
			visited[i] = false;
		}
	}
	return k;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i=0;i<MAXN;i++)
		for(int j=0;j<MAXN;j++) bmap[i][j] = INT_MAX;

	
	int tmp;
	int tmpa,tmpt;
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		cin >> tmp;
		for(int j=1;j<=tmp;j++){
			cin >> a[j] >> t[j];
			for(int k=1;k<j;k++){
				bmap[a[k]][a[j]] = min(bmap[a[k]][a[j]],t[k] + t[j]);
				
				bmap[a[j]][a[k]] = bmap[a[k]][a[j]];
		}
		}
	}
	
		int rgin,rgout;
		while(q--){
			cin >> rgin >> rgout;
			visited[rgin] = true;
			cout << kru1(rgin,rgout, 0) + (w[rgin] + w[rgout]) << "\n";
		}
		return 0;
} 



/*

*/ 
