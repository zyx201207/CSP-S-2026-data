#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,l=1,r=1;
long long m,sum=0;
long long sz[500010];
void solve(){
	while(r<n&&l<=r){
		if(sum+(r-l+1)*(sz[r+1]-sz[r])<=m){
			sum+=(r-l+1)*(sz[r+1]-sz[r]);
			r++;
		}else{
			break;
		}
	}
	return;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>sz[i];
	}
	sort(sz+1,sz+1+n);
	solve();
	int ans=r;
	while(r<n&&l<n){
		if(sum-sz[r]+sz[l]+(r-l)*(sz[r+1]-sz[r])<=m){
			l++;
			r++;
			sum=sum-sz[r]+sz[l]+(r-l)*sz[r+1];
			solve();
		}else{
			sum=sum-sz[r]+sz[l];
			l++;
		}
		ans=max(ans,r-l+1);
		if(l==r){
			l=r+1;
			r=r+1;
			solve();
		} 
		ans=max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
