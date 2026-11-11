#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		ll ans=-1;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}else if(n==m){
		ll ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}else if(n-1==m){
		ll ans;
		int v,mn=0x3f3f3f;
		for(int i=1;i<=n;i++){
			ll x=a[i];
			int cnt;
			while(x){
				if(x%2==1){
					cnt++;
				}
				x/=2;
			}
			if(cnt<mn){
				mn=cnt;
				v=i;
			}
		}
		if(v!=1){
			ans=a[1];
			ans=ans&a[2];
		}else{
			ans=a[2];
		}
		for(int i=3;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}else if(a[n]=n-1){
		ll ans=a[n];
		for(int i=1,j=n-1;i<=m;i++,j--){
			ans=ans&a[j];
		}
		cout<<ans;
		return 0;
	}else{
		ll ans;
		ans=a[n];
		for(int i=1,j=n-1;i<=m;j--,i++){
			ans=ans&a[j];
		}
		cout<<ans;
	}
	return 0;
}
