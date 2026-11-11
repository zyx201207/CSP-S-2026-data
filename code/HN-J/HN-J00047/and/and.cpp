#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+7;
int n,m,a[maxn],vis[maxn];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[i]=1;
	}
	int ans=0;
	for(int x=29;x>=0;x--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1&&((a[i]>>x)&1)==1){
				cnt++;
			}
			if(cnt<m){
				continue;
			}
			ans|=(1<<x);
		}
		for(int i=1;i<=n;i++){
			if(cnt>=m){
				if(vis[i]==1&&((a[i]>>x)&1)==0){
					vis[i]=0;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
11 11111 1100 1100 
*/
