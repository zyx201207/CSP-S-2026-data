#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N];
int sum[N],ans;
bool check(int mid){
	for(int i=mid;i<=n;i++){
		int l=i-mid+1;
		if(sum[i]-sum[l]-(a[i]-a[l])*(l-1)<=m) return 1;
	}
	return 0;
}
signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum[1]=0;
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
	}
//	for(int i=1;i<=n;i++){
//		cout<<sum[i]<<" ";
//	}
//	cout<<"\n";
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
//		cout<<mid<<"\n";
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans<<"\n";
	
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
