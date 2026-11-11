#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}if(m==2){
		ll maxx=-4e18;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ll ans=(a[i]&a[j]);
				maxx=max(maxx,ans);
			}
		}cout<<maxx;
		return 0;
	}if(m==n-1){
		ll vis[2000005],maxxx=-4e18,cnt=0;
		for(int i=i;i<=n;i++){
			vis[i]=1;
			for(int j=1;j<=n;j++){
				if(vis[1]==1) cnt=a[2],vis[2]=1;
				else cnt=a[1];
				if(vis[j]==0) cnt&=a[j];
			}maxxx=max(maxxx,cnt);
		}
	}
	return 0;
}

