#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 5e5+5;
int n,ans;
ll m,a[N],sum = 0ll;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	ans = 1;
	for(int i=2,j=1;i<=n;++i){
		sum += (ll)(i-j)*(a[i]-a[i-1]);
		while(sum > m){
			sum -= (a[i]-a[j]);
			++j;
		}
		ans = max(ans,i-j+1);
	}
	printf("%d",ans);
	return 0;
}
