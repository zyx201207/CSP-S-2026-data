#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int n,m,a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==2){
		int maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		int maxx=0,ans=a[2];
		for(int i=3;i<=n;i++){
			ans=ans&a[i];
		}
		for(int i=2;i<=n;i++){
			maxx=a[1];
			for(int j=1;j<=n;j++){
				if(i==j){
					continue;
				}
				maxx=maxx&a[j];
			}
			ans=max(maxx,ans);
		}
		cout<<ans;
		return 0;
	}
	
	return 0;
}
