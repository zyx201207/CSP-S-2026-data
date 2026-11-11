#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int N = 5e5+5;
int n,m;
int a[N],s[N];
int b[N];
bool check(int l,int r){
	return (b[r]-(l-1)*a[r]+s[l-1]<=m);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++) scanf("%lld",&a[i]);
	stable_sort(a+1,a+n+1); 
//	for(int i = 1;i<=n;i++) cout<<a[i]<<' ';
	for(int i = 1;i<=n;i++){
		s[i]= s[i-1]+a[i];
	}
	for(int i = 1;i<=n;i++) b[i] = (i-1)*a[i]-s[i-1];
	int ans = 0;
	for(int i = 1;i<=n;i++){
		int l = i+1,r = n;
		int pos = 0;
		while(l<=r){
			int mid = (l+r)>>1;
			if(check(i,mid)) pos = mid,l = mid+1;
			else r = mid-1;
		}
		ans = max(ans,pos-i+1);
	}
	cout<<ans<<'\n';
	return 0;
}
