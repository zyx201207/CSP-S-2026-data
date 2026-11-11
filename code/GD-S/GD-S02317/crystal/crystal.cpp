#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,j=1,maxn;
int a[500005];
int sum[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int need=(i-j+1)*a[i]-(sum[i]-sum[j-1]);
		//cout<<i<<" "<<j<<" "<<a[i]<<" "<<(sum[i]-sum[j-1])<<"\n"; 
		while(m<need){
			need-=a[i]-a[j];
			j++;
		} 
		maxn=max(maxn,i-j+1);
	}
	cout<<maxn;
	return 0;
}  
