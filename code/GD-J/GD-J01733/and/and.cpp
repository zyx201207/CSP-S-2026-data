#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];
bool vis[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int j=30;j>=0;j--){
		int t=(1<<j),cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			if(a[i]&t) cnt++;
		}
		if(cnt>=m){
			for(int i=1;i<=n;i++){
				if(vis[i]) continue;
				if(a[i]&t) continue;
				vis[i]=1;
			}
			ans+=t;
		}
	}
	cout<<ans;
	return 0;
}
