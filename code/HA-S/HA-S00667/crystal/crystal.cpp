#include<bits/stdc++.h>
using namespace std;
//¹Ø×¢luogu 1406766 Ð»Ð»ß÷ 
const int N=5e5+5;
long long n,m,ans,a[N],f[N];
bool check(int x){
	for(int i=x;i<=n;i++){
		if(x*a[i]-(f[i]-f[i-x])<=m) return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)f[i]=f[i-1]+a[i];
	int l=1,r=n;
	while(l<=r){
		long long mid=(l+r)>>1ll;
		if(check(mid))l=mid+1ll,ans=max(ans,mid);
		else r=mid-1ll;
	}
	cout<<ans;
	return 0;
} 
