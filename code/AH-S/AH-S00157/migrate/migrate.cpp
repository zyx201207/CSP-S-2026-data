#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
const int inf=2e9;
const int mod=1e9+7;

int t,c;
int n,d,mn=mod,cnt;
int a[N];
void dfs(int r,int p,int sum){
	if(sum>mn) return;
	if(p==r){
		if(sum<mn){
			mn=sum; cnt=1;
		}
		else if(sum==mn){
			cnt++;
		}
		return;
	}
	for(int i=p+1;i<=r;i++) if(abs(a[p]-a[i])<=d){
		dfs(r,i,sum+1);
	}
}
void solve()
{
	int ans=0;
	cin >> n >> d;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int l=1;l<=n;l++){
		for(int r=l+1;r<=n;r++){
			cnt=0;mn=mod;
			dfs(r,l,0);
//			cout << l << " " << r << " " << cnt << endl;
			if(cnt==2) ans++;
		}
	}
	cout << ans << endl;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		solve();
	}
	return 0;
}

