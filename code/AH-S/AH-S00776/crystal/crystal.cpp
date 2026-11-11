#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int z[500005];
bool c(int r,int w,int m){
	int sy=z[r]-z[w]-(w-1)*(a[r]-a[w]);
	return sy<=m;
}
int js(int l,int r,int m,int rr){
	int ans=r;
	while(l<=r){
		int mid=(l+r)/2;
		if(c(rr,mid,m)){
			r=mid-1;
			ans=mid;
		}else{
			l=mid+1;
		}
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		z[i]=z[i-1]+(a[i]-a[i-1])*(i-1);
	}
	int ans=1;
	for(int i=2;i<=n;i++){
		int l=z[i]-m;
		int w=js(1,i,m,i);
		ans=max(ans,i-w+1);
	}
	cout<<ans;
	return 0;
}
