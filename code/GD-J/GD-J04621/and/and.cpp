#include<bits/stdc++.h>
#define int long long
#define uint unsigned int
#define all(x) x.begin(),x.end()
#define inf 0x3f3f3f3f
using namespace std;
const int maxN = 2e5 + 5;
int n,m; int u[maxN]; int mmax = -1;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> u[i];
	}for(int i=0;i<n;i++){
		mmax = max(mmax,u[i]);
	}cout << mmax;
	return 0;
}
