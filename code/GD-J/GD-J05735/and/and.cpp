#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N],ans;
bool vis[N];
int n,m;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int k=30;k>=0;k--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i])continue;
			if(a[i]&(1<<k))cnt++;
		}
		if(cnt>=m){
			ans+=(1<<k);	
			for(int i=1;i<=n;i++){
				if(!(a[i]&(1<<k)))vis[i]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}

