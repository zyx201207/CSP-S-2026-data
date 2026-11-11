#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long n,m,a[N],s[N];
bool check(long long mid){
	for(int i=mid;i<=n;i++){
		long long tmp = s[i] - s[i-mid];
		long long t = a[i] * mid;
		if(tmp + m >= t){
			return 1;
		}
	}
	return 0;
}
long long ef(long long l,long long r){
	long long ans = 0;
	while(l <= r){
		long long mid = (l+r)/2;
		if(check(mid)){
			l = mid+1;
			ans = mid;
		}else r = mid-1;
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i] = s[i-1] + a[i];
	}
	cout<<ef(1,n);
	return 0;
}
/*
8444KB
5 5
1 2 4 8 9

*/
