#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	ll n,m;cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int ans=1;ll sum=0;
	for(int i=1,j=1;i<=n;i++){
		sum+=(i-j)*(a[i]-a[i-1]);
		while(sum>m) sum-=a[i]-a[j],j++;
		ans=max(ans,i-j+1);
	}cout<<ans;
}
