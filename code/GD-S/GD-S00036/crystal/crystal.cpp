#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],sum[N];
int check(int x){
	for(int i=x;i<=n;i++){
		int S=sum[i]-sum[i-x];
		int nd=a[i]*x-S;
		if(nd<=m)	return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	int mn=1e18,mx=1e18;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n,mid,ans=0;
	while(l<=r){//¶àÉÙ¿É 
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else	r=mid-1;
	}
	cout<<ans;
	return 0;
}
