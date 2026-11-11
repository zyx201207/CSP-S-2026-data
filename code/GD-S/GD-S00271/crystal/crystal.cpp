#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N = 5e5+10;
int a[N],s[N],sum[N];
int n,m;
bool check(int l,int r){
	if(sum[l]-sum[r+1]-(r-l+1)*s[r]<=m) return true;
	else return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = n-1;i>=1;i--){
		s[i] = s[i+1]+(a[i+1]-a[i]);
	}
	for(int i = n-1;i>=1;i--){
		sum[i] = sum[i+1]+s[i];
	}
	int maxn = 1;
	for(int i = 1;i<=n;i++){
		int l = 1,r = i,ok;
		while(l<=r){//°üÀ¨mid 
			int mid = (l+r)/2;
			if(check(mid,i)){
				r = mid-1;
				ok = mid;
			}
			else l = mid+1;
		}
		maxn = max(maxn,i-ok+1);
	}
	cout<<maxn<<"\n";
	return 0;
}
