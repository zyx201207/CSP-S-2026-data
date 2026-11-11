#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int maxn=-1;
int a[500005],k[500005];
int f(int maxn){
	int cnt=1;
	for(int i=1;i<=n;i++){
		if(k[i]==k[i+1]){
			cnt++;
		}
	}
	return max(maxn,cnt);
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n; i>=1; i--) {
		int sum=0;
		for(int x=1;x<=n;x++){
			k[x]=a[x];
		}
		for(int j=i-1; j>=1; j--) {
			sum+=a[i]-a[j];
			if(sum>m) {
				break;
			}
			k[j]=a[i];
		}
		if(sum<=m){
			maxn=f(maxn);
		}
	}
	cout<<maxn;
	return 0;
}
