#include<bits/stdc++.h>
using namespace std;
#define int long long

const int M=510;
const int N=5e5+10;

int ins[N];
vector <pair<int,int> > li[M];
int t1[5010][5010];
int vis[N],vis22[N][3],ans=LLONG_MAX;

struct node {
	int to,l,ti;	
};
;
int vis3[M];

int c,n,m,d,q;

void solve1() {
	memset(t1, 0x3f, sizeof t1);
	for (int i=1;i<=n;i++) {
		t1[li[i][0].first][li[i][1].first]=t1[li[i][1].first][li[i][0].first]=li[i][0].second+li[i][1].second;
		t1[i][i]=0;
	}
	for (int k=1;k<=m;k++) {
		for (int i=1;i<=m;i++) {
			for (int j=1;j<=m;j++) {
				t1[i][j]=min(t1[i][k]+t1[k][j], t1[i][j]);
			}
		}
	}
	while (q--) {
		int l,r;
		cin >> l >> r;
		cout << t1[l][r]+ins[l]+ins[r] << '\n';	
		
	}
	return ;
}

void solve2() {
	for (int i=1;i<=n;i++) {
		for (auto ed:li[i]) {
			vis[ed.first]+=i;
			vis22[ed.first][i]=ed.second;
		}
	}
	int mi=LLONG_MAX;
	for (int i=1;i<=m;i++) {
		cout << vis[i] << " ";
		if (vis[i]==3) {
			mi=min(mi, vis22[i][1]+vis22[i][2]);
		}
	}
	while (q--) {
		int l,r;
		cin >> l >> r;
		if (vis[l]==vis[r]&&vis[l]==3) {
			cout << min(vis22[l][1]+vis22[r][1], vis22[l][2]+vis22[r][2])+ins[l]+ins[r];	
		} else if (vis[l]==vis[r]) {
			cout << ins[l]+ins[r]+vis22[l][vis[l]]+vis22[r][vis[r]];
		} else if (vis[l]==3) {
			cout << ins[l]+ins[r]+vis22[l][vis[r]]+vis22[r][vis[r]];	
		} else if (vis[r]==3) {
			cout << ins[l]+ins[r]+vis22[l][vis[l]]+vis22[r][vis[l]];
		} else {
			cout << ins[l]+ins[r]+mi+vis22[l][vis[l]]+vis22[r][vis[r]];
		}	
		cout << '\n';
	}
	return ;
}


signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);	
	
	cin >> c >> n >> m >> d >> q;
	for (int i=1;i<=m;i++) {
		cin >> ins[i];	
	}
	int num=0;
	for (int i=1;i<=n;i++) {
		int k;
		cin >> k;
		if (k<=2) num++;
		if (k==1) continue;
		for (int j=1;j<=k;j++) {
			int to, ti;
			cin >> to >> ti; 
			li[i].push_back({to, ti});
		}
	}
	if (num==n) {
		solve1();
		return 0;
	}
	if (n==2) {
		solve2();
		return 0;	
	}
	solve2();
	return 0;
}

