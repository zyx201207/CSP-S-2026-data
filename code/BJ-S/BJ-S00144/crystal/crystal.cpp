#include<bits/stdc++.h>
#define int long long
#define N 500010
using namespace std;
int n,m,a[N],s[N],ans;
int solve(int l,int r){
	return a[r]*(r-l+1)-(s[r]-s[l-1]);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=i,r=n,best;
		while(l<=r){
			int mid=(l+r)/2;
			if(solve(i,mid)<=m){
				l=mid+1,best=mid;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,best-i+1);
	}
	cout<<ans;
	return 0;
}