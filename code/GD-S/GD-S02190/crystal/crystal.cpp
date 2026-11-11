#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500010];
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
	}
	int f=0;
	for(int i=4; i<=n; i++){
		if(a[i]-a[i-1] != a[i-2]-a[i-3]){
			f=1;
		}
	}
	if(f==0){
		long long t=a[2]-a[1], cnt=0;
		for(long long i=1; i<=n; i++){
			cnt+=i*t;
			if(cnt>m){
				cout<<i;
				break;
			}
		}
		return 0;
	}
	sort(a+1, a+n+1);
	int ans=0;
	for(int i=1; i<=n; i++){
		long long sum=0;
		int ff=0;
		for(int j=i; j>=1; j--){
			sum+=a[i]-a[j];
			if(sum>m){
				ans=max(ans, i-j);
				ff=1;
				break;
			}
		}
		if(ff==0){
			ans=max(ans, i);
		}
	}
	cout<<ans;
	return 0;
} 
