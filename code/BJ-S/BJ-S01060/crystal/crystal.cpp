#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
ll n,m,a[maxn],sum[maxn],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	ll l=1;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int r=1;r<=n;r++){
		while(l<r&&a[r]*(r-l+1)-(sum[r]-sum[l-1])>m){
			l++;
		}
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
