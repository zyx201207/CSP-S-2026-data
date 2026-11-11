#include<bits/stdc++.h>
using namespace std;
const int MAX=5e5+10;
typedef long long ll;
ll n,m,a[MAX];
ll l=1,cnt=0,need=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){scanf("%lld",a+i);}
	sort(a+1,a+1+n);
	a[0]=a[1];
	for(ll r=1;r<=n;r++){
		need+=(r-l)*(a[r]-a[r-1]);
		while(need>m && l<r){need-=a[r]-a[l];l++;}
		cnt=max(cnt,r-l+1);
//		printf("%lld %lld %lld\n",l,r,need);
	}
	printf("%lld",cnt);
	return 0;
}
