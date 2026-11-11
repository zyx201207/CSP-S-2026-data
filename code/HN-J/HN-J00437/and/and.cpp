#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MX=2e5+1;
int n,m,a[MX],vis[MX];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int ans=0;
	for(int i=29;i>=0;--i){
		int cnt=0;
		for(int j=1;j<=n;++j){
			if(!vis[j]&&a[j]&(1<<i)){
				++cnt;
			}
		}
		if(cnt>=m){
			for(int j=1;j<=n;++j){
				if(!vis[j]&&!(a[j]&(1<<i))){
					vis[j]=1;
				}
			}
			ans^=(1<<i);
		}
	}
	cout<<ans;
	return 0;
}
