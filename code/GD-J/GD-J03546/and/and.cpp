#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

long long a[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long m,n;
	cin>>n>>m;
	for(long long i = 1;i <= n;i++) cin>>a[i];
	if(m == 1){
		long long max_ = -1;
		for(long long i = 1;i <= n;i++) max_ = max(max_,a[i]);
		cout<<max_;
		return 0;
	}
	if(m == n){
		long long ans = a[1];
		for(long long i = 2;i <= n;i++) ans = ans & a[i];
		cout<<ans;
		return 0;
	}
	if(m == 2){
		long long max_ = -1;
		for(long long i = 1;i <= n;i++){
			for(long long j = i + 1;j <= n;j++){
				max_ = (max_,a[i] & a[j]);
			} 
		}
		cout<<max_;
		return 0;
	}
}
