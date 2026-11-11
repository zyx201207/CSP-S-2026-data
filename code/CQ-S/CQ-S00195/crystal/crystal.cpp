#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],h[500005];
signed main(){
	//printf
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) h[i] = h[i-1]+a[i];
	for(int i=1;i<=n;i++){
		if(a[i]*(i-1)-h[i-1]>m){
			cout<<i-1;
			return 0;
		}
	}
	cout<<n;
	return 0;
}

