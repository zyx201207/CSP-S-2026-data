#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],maxn_=-1,maxn=-1;
int main(){
	freopen("and3.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn_=max(maxn_,a[i]);
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		cout<<maxn_;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					long long ans=a[i]&a[j];
					maxn=max(maxn,ans);
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==n-1){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		for(int i=1;i<=n;i++){
			long long abab=ans&a[i];
			maxn=max(maxn,abab);
		}
		cout<<maxn;
		return 0;
	}
	if(m==3){
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j&&i!=k&&j!=k){
						long long ans=a[i]&a[j]&a[k];
						maxn=max(maxn,ans);
					}
				}
			}
		}
		cout<<maxn;
		return 0;
	}
	return 0;
}

