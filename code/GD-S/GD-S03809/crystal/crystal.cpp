#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1; i<=n; i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	int k=0,ans=0;
	for(int i=1,j=1; i<=n; i++){
		int d=a[i]-a[i-1];
		k+=(i-j)*d;
		while(k>m){
			k-=(a[i]-a[j]);
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
