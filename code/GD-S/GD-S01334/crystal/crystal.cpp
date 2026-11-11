#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,ans;
ll m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	ll sum=0;
	for(int i=1,it=1;i<=n;i++){
		while(it<=i&&(i-it)*a[i]-sum>m) sum-=a[it],it++;
		sum+=a[i];ans=max(ans,i-it+1);
	}cout<<ans;
	return 0;
}
