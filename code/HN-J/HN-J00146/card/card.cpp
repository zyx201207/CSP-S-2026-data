#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pait pair<int,int>
const int N = 5e5+7;
const int M = 21;
const int px = 131;
const int mod = 998244353;
const int Mod = 1e9+7;
int n,m,a[N],b[N],c[N];
bool vis[N];
signed main(){
	freopen("card4.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int k=1;k<=n;++k){
		int r = 0;
		for(int i=1;i<=m;++i) vis[i] = 0;
		for(int i=k;i<=n;++i){
			bool flag = 0;
			for(int j=1;j<=r;++j){
				if(a[i] == b[j]){
					r = j,b[r] = a[i];
					flag = 1;
					break;
				}
			}
			if(!flag) b[++r] = a[i];
		}
		for(int i=1;i<=r;++i) c[b[i]] += !vis[b[i]],vis[b[i]] = 1;
	}
	for(int i=1;i<=m;++i) cout<<c[i]<<' ';
	return 0;
}
