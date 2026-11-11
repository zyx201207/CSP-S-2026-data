#include <bits/stdc++.h>
using namespace std;

struct Rhall {
	int point;
	int t;
	Rhall() {
		// There is nothing....
	}
	Rhall(int point,int t) {
		this->point = point;
		this->t = t;
	}
}; 

int c,n,m,d,q;
int dhall[500001];
vector<Rhall> routes[501];
vector<int> ors[500001];
int si,ei;

bool td[500001];
long long dp[500001];
int ki,po,ti,ro;

long long dfs(int);
long long dfs(int,int);

long long dfs(int si,int ro) {
	int bas=0;
	long long res = LONG_LONG_MAX-INT_MAX;
	td[si] = true;
	for (int i=0;i<routes[ro].size();i++) {
		int p = routes[ro][i].point;
		if (si == p) bas = routes[ro][i].t;	
		else if (!td[p]) res = min(res,dfs(p)+routes[ro][i].t);	
	}
	td[si] = false;
	return bas+res;
}

long long dfs(int si) {
	if (si == ei) return 0L;
	else if (dp[si] > 0) return dp[si];
	long long res = LONG_LONG_MAX-INT_MAX;
	for (int i=0;i<ors[si].size();i++) {
		res = min(res,dfs(si,ors[si][i]));
	}
	dp[si] = res;
	return res;
}

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++) {
		scanf("%d",dhall+i);
	}
	for (int i=0;i<n;i++) {
		scanf("%d",&ki);
		for (int j=0;j<ki;j++) {
			scanf("%d%d",&po,&ti);
			ors[po].push_back(i);
			routes[i].push_back(Rhall(po,ti));
		}
	}
	while (q--) {
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&si,&ei);
		printf("%lld\n",dfs(si)+dhall[si]+dhall[ei]);
	}
	
	return 0;
}
// FUCKCCF
