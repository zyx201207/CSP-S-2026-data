#include<bits/stdc++.h>
using namespace std;
long long a[500005], sum[500005];
int ans;
long long n,m;
bool check(int x){
	bool flag = 0;
	for(int i = 1; i<=n-x+1; i++){
		if(sum[i+x-1] - sum[i-1] + m >= x*a[i+x-1]){
			flag = 1;
		}
//		cout<<i<<" "; 
	}
	return flag;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ans = -1;
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w",stdout); 
	cin>>n>>m;
	bool flag1 = 0, flag2 = 0;
	for(int i =1; i<=n; i++){
		cin>>a[i];
		if(a[i] != i){
			flag1 = 1;
		} 
	}
	if(flag1 == 0){
		long long cnt1 = 0;
		for(long long i = 1; ; i++){
			cnt1+=i;
			if(cnt1>m){
				cout<<i;
				return 0;
			}
		} 
	}
	sort(a+1,a+n+1);
	int k = a[2] - a[1];
	for(int i = 1; i<=n; i++){
		if(a[i] - a[i-1] != k&&a[i]!=1){
			flag2 = 1;
		}
		sum[i] = sum[i-1]+a[i];
	}
	if(flag2 == 0){
		long long cnt2 = 0,q = 0;
		for(long long i = k; ; i+=k){
			cnt2+=i;
			q++;
			if(cnt2>m){
				cout<<q;
				return 0;
			}
		}
	}
	int l = 1, r = n;
	while(l<r){
		int mid = (l+r)/2;
		if(check(mid)){
			l = mid; 
		}else{
			r = mid - 1;
		}
		if(ans == mid){
			break;
		}else{
			ans = mid;
		}
	}
	if(check(ans+2)){
		cout<<ans+2;
	}else if(check(ans+1)){
		cout<<ans+1;
	}else if(check(ans)){
		cout<<ans;
	}else if(check(ans-1)){
		cout<<ans-1;
	}else{
		cout<<ans-2;
	}
	return 0;
} 
