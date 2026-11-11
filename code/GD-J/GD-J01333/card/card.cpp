#include<bits/stdc++.h>
#define per(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,y,x) for(int i=y;i>=x;i--)
#define pob pop_back
#define pb push_back
using namespace std;
int n,m,a[500005],cnt[300005],ans[300005];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	per(i,1,n) cin>>a[i];
	per(k,1,n) {
		vector<int> v;
		per(i,1,m) cnt[i]=0;
		per(i,k,n) {
			if(cnt[a[i]]==1) {
				int x=0;
				per(j,0,v.size()-1) if(v[i]==a[i]) {x=i;break;}
				rep(j,v.size()-1,x) cnt[v[i]]--,v.pob();
			}
			v.pb(a[i]);
			cnt[a[i]]++;
		}
		for(int x:v) ans[x]++;
	}
	per(i,1,m) cout<<ans[i]<<" ";
	return 0;
}
