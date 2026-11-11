#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
long long a[maxn],p[maxn],n,m,l,r,ans;
bool check(long long mid){
	for(int i = 1;i+mid-1<=n;i++){
		long long t = a[i+mid-1];
		if(t*mid<=p[i+mid-1]-p[i-1]+m){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1;i<=n;i++){
		p[i] = p[i-1]+a[i];
	}
	l = 1,r = n;
	while(l<=r){
		long long mid = (l+r)/2;
		if(check(mid)){
			ans = mid;
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}
	cout<<ans;
	return 0;
}
