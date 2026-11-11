#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e12
int n,m,ans=0,mid,l,r,a[500008];
bool check(int x){
	int s=0;
	for(int i=x;i>=1;i--){
		s+=(a[x]-a[i]);
	}
	return s<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	freopen("test.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	l=0,r=n;
	sort(a+1,a+1+n);
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans<<'\n';
//	for(int i=1;i<=n;i++){
//		if(check(i)==0){
//			cout<<i;
//			return 0;
//		}
//	}
//	cout<<'\n';
	return 0;
}
