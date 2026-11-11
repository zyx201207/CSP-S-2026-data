#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll m,n,a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	ll l=0,r=1,ans=1;
	while(l<=r&&r<=n){
		if((r-l)*a[r]-(b[r]-b[l])<=m){
			ans=max(ans,r-l);
			r++;
		}else{
			l++;
		}
	}
	cout<<ans;
	return 0;
}
