#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,ans=0;
ll m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=n,j=n;i;--i){
		while(j&&m>=a[i]-a[j])m-=a[i]-a[j],j--;
		ans=max(ans,i-j),m+=(a[i]-a[i-1])*(i-j-1);
	}
	printf("%d",ans);
	return 0;
}
