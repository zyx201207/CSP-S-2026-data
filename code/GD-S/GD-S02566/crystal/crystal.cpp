#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	if(n%2==1){
		long long mid = a[n/2+1];
		long long tmp = m;
		long long ans = 1;
		for(int i=n/2;i>=1;i--){
			if(m<(mid-a[i])){
				break ;
			}
			ans++;
			m-=(mid-a[i]);
		}
		cout << ans;
	}else{
		long long mid = a[n/2];
		long long tmp = m;
		long long ans = 1;
		for(int i=n/2-1;i>=1;i--){
			if(tmp<(mid-a[i])){
				break ;
			}
			ans++;
			tmp-=(mid-a[i]);
		}
		cout << ans;
	}
	return 0;
} 
