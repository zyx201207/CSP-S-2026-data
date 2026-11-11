#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
int a[200001];

int dfs (int u,int dis,int xu){
	if (dis == m + 1) return u;
	int ans = -1;
	for (int i = xu + 1;i <= n;i ++){
		ans = max (ans,dfs (u & a[i],dis + 1,i));
	}
	return ans;
}

signed main(){
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	
	cout << dfs (INT_MAX,1,0);
	return 0;
}

