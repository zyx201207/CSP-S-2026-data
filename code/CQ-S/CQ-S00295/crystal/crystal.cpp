#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
const int N=5e5+10;
int m;
int a[N];
int sum[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
//	for(int i=1;i<=n;i++) cout<<sum[i]<<' ';cout<<'\n';
	for(int i=1,j=1;i<=n;i++){
		while(j<=i&&a[i]*(i-j+1)+sum[j-1]-sum[i]>m) j++;
		ans=max(ans,i-j+1);
//		cout<<a[i]*(j-i+1)<<' '<<sum[i]-sum[j-1]<<' '<<m<<' '<<i<<' '<<j<<'\n';
	} 
	cout<<ans;
	return 0; 
}
