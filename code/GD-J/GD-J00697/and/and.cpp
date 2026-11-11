#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200008],vis[200008],ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[i]=0;
	}
	for(ll k=(1<<30);k>=1;k/=2){
		ll cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				continue;
			}
			if((a[i]&k)>0){
				cnt++;
			}
		}
		if(cnt>=m){
			ans+=k;
			for(int i=1;i<=n;i++){
				if((a[i]&k)==0){
					vis[i]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
