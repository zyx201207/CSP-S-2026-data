#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e5+5;
long long a[N],pre[N];
long long n,m;
bool check(long long l,long long r){
	long long sum = 0;
	sum = a[r]*(r-l+1)-(pre[r]-pre[l-1]);
	return sum<=m;
}
void solve(){
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++){
		pre[i] = pre[i-1]+a[i];
	}
	long long idl = 0,idr = 0,ans = 0;
	for(long long i = 1;i<=n;i++) {
		long long l = i,r = n,nowr = 0,now;
		while(l<=r){
			long long mid = (l+r)>>1;
			if(check(i,mid)){
				l = mid + 1;
				nowr = mid;
			}else{
				r = mid - 1;
			}
		}
		now = nowr-i+1;
		if(now>ans) {
			ans = now;
			idl = i,idr = nowr;
		}
	}
	cout<<idl<<" "<<idr<<endl;
	cout<<ans<<endl;
	return;
} 

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
