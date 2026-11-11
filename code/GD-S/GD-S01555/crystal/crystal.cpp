#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,m;
long long ans = 0;
bool check(long long tt){
	long long sum = 0;
	for(int i = 1;i<=tt;i++){
		sum+=(a[tt] - a[i]);
	}
	if(sum <= m){
		return 1;
	}
	else{
		return 0;
	}
}
void find(long long l,long long r){
	long long mid  = l + (r - l)/2;
	while(l<r){
		mid = l + (r-l) / 2;
		if(check(mid)){
			l = mid+1;
			ans = max(ans,mid);
		}
		else{
			r = mid;
		}
	}
	ans = max(ans,l-1);
	return;
}
int main(){
	cin.tie(0);
	cout.tie(0);
	std::ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	find(1,n);
	cout<<ans;
	return 0;
}
