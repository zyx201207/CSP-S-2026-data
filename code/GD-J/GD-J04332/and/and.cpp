#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m,a[N],ans;
bool vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=29;j>=0;j--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			if(a[i]&(1<<j)) cnt++;
		}
		if(cnt>=m){
			ans|=(1<<j);
			for(int i=1;i<=n;i++){
				if(vis[i]) continue;
				if(!(a[i]&(1<<j))) vis[i]=true;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}

