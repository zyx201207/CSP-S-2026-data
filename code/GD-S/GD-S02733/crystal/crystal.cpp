#include<iostream>
#include<algorithm>
#define int long long
#define N 500010
using namespace std;
int n,m,a[N],pre[N];
bool check(int k){
	for(int i=1;i<=n-k+1;i++){
		//cout<<i<<" "<<mid<<'\n';
		if(k*a[i+k-1]-(pre[i+k-1]-pre[i-1])<=m)return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
//	for(int i=1;i<=n;i++){
//		cout<<pre[i]<<" ";
//	}
//	cout<<'\n';
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid))l=mid;
		else r=mid-1;
		//cout<<mid<<" "<<check(mid)<<'\n';
	}
	//cout<<check(3);
	cout<<l;
	return 0;
} 
