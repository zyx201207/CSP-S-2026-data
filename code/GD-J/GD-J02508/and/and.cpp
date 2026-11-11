#include<bits/stdc++.h>
using namespace std;
long long n,k,maxn=-1;
long long a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n;
	cin >> k;
	for(long long i=1;i<=n;i++){
		cin >> a[i];
	}
	if(k==n){
		long long ans=a[1];
		for(long long i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout << ans;
	}
	else if(k==1){
		for(long long i=2;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout << maxn;
	}
	else if(k==2){
		for(long long i=1;i<=n;i++){
			for(long long j=i;j<=n;j++){
				long long s=a[i]&a[j];
				maxn=max(maxn,s);
			}
		}
		cout << maxn;
	}
	return 0;
}
