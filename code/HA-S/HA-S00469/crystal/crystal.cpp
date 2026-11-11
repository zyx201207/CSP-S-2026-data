#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=6e5;
int n;
ll m,a[N];
bool check(ll x,int _){
	ll ans=0;
	for(int i=1;i<_;i++)
		ans+=x-a[i];
	return ans<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	ll l=1,r=n,mid;
	while(l<r){
		mid=(l+r+1)>>1;
		if(check(a[mid],mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}printf("%lld",l);
	return 0;
}

