#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+15;
#define ll long long
int n;
ll m,a[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)a[i]+=a[i-1];
	int ans=0;
	for(int i=1,j=1;i<=n;++i){
		ll x=a[i]-a[i-1];
		while(1ll*(i-j+1)*x-(a[i]-a[j-1])>m)++j;
		ans=max(ans,i-j+1);
	}
	printf("%d\n",ans);
}

