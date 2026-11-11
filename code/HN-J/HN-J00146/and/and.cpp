#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pait pair<int,int>
const int N = 2e5+7;
const int M = 21;
const int px = 131;
const int mod = 998244353;
const int Mod = 1e9+7;
int n,m,a[N];
bool vis[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	int sum = 0,ans = n;
	for(int j=30;j>=0;--j){
		int kcnt = 0;
		for(int i=1;i<=n;++i){
			if(!vis[i] && ((a[i] >> j) & 1) == 1) kcnt++;
		}
		if(kcnt >= m){
			sum += (1 << j);
			for(int i=1;i<=n;++i){
				if(!vis[i] && ((a[i] >> j) & 1) == 0) vis[i] = 1,ans--;
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}
