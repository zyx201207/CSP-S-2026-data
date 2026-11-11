#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,l=1,r,ans;
ll a[N],m,c[N];
bool check(int k){
	ll now=0,sum=0;
	int i=1;
	for(;i<k;i++) now+=(ll)(i*c[i]),sum+=c[i];
	i--;
	while(now>m&&i<n) i++,now+=(c[i]*((ll)(k-1)))-sum,sum+=c[i]-c[i-k+1];
	return (now<=m);
}
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);	
	scanf("%d%lld",&n,&m),r=n;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++) c[i-1]=a[i]-a[i-1];
	while(l<=r){
		int mid=((l+r)>>1);
		if(check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
