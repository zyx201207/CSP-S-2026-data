#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ans,cnt[105],mp[200005];
vector<int> vis[105];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=30;j>=0;j--){
			if(((a[i]>>j)&1)) cnt[j]++;
			else vis[j].push_back(i);
		}
	}
	for(int i=30;i>=0;i--){
		if(cnt[i]>=m){
			ans=(1<<i)|ans;
			for(int j=0;j<vis[i].size();j++){
				int x=vis[i][j];
				if(mp[x]) continue;
				mp[x]=1;
				for(int j=30;j>=0;j--) cnt[j]-=((a[x]>>j)&1);
			}
		}
	}
	cout<<ans;
	return 0;
}
