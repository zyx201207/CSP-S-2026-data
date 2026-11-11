#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=5e5+5;
ll a[N],n,m,c[N],sum;
ll ans,mx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	ans=1;
	for(int i=2;i<=n;i++){
		sum+=c[i]*ans;
		while(sum>m){
			sum-=(a[i]-a[i-ans]);
			ans--;
		}
		ans++;
		mx=max(ans,mx);
	}
	cout<<mx<<'\n';
	return 0; 
} 
