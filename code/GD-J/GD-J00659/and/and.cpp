#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int n,m;
ll a[200005];
bool vis[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[i]=true; 
	}
	for(int i=30;i>=0;i--){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(((a[j]>>i)&1) and vis[j]){
				sum++;
			}
		}
		if(sum==m){
			for(int j=1;j<=n;j++){
				if(!((a[j]>>i)&1)){
					vis[j]=0;
				}
			}
			break;
		}else if(sum>m){
			for(int j=1;j<=n;j++){
				if(!((a[j]>>i)&1)){
					vis[j]=0;
				}
			}
		}
	}
	ll ans=INT_MAX;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			ans=(ans&a[i]);
		}
	} 
	cout<<ans;
	return 0;
} 
/*

*/

