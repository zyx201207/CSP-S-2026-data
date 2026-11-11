#include<bits/stdc++.h>
using namespace std;

long long n,m,a[200005];
set<long long> s;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long A=1,B=1;
	for(int i=0;i<=30;++i){
		s.insert((1<<i));
	}
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(s.count(a[i]+1) == 0){
			A=0;
		}
		if(a[i] != i-1){
			B=0;
		}
	}
	sort(a+1,a+1+n);
	if(m == 1){
		cout<<0;
	}else if(m == n){
		long long ans=a[n];
		for(int i=n;i>=1;--i){
			ans &= a[i];
		}
		cout<<ans;
	}else if(m == 2 and n <= 2000){
		long long ans=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				long long tot = a[i] & a[j];
				ans = max(ans,tot);
			}
		}
		cout<<ans;
	}else{
		long long ans=a[n];
		long long have=0;
		for(int i=n;i>=1;--i){
			if(have == m) break;
			ans &= a[i];
			have++;
		}
		cout<<ans;
	}
	return 0;
}
