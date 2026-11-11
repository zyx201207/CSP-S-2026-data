#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005];
int ans;
int vis[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j]) continue;
			if(a[j]&(1ll<<i)) cnt++;
		}if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(vis[j]) continue;
				if(!(a[j]&(1ll<<i))) vis[j]=1;
			}ans+=(1ll<<i);
		}
	}cout<<ans;
	return 0;
} 
