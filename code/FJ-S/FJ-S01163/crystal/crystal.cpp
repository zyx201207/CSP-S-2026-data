#include <bits/stdc++.h>
#define ll long long
#define lowbit(x) (x&(_x))
using namespace std;
const int N = 1e6+10,INF = 0x3f3f3f3f;
int n,ans;
ll m;
ll a[N],d[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i = 1;i<=n;i++)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(int i = 2;i<=n;i++)a[i] -= a[1];
	a[1] = 0;
	for(int i = 1;i<=n;i++)d[i] = a[i]-a[i-1];
	ll val = 0;
	for(int i = 1,j =1;i<=n;i++){
		val += d[i]*(i-j);
		while(j <= i && val > m){
			val -= a[i]-a[j];
			j++; 
		}
		ans = max(ans,i-j+1);
	}
	printf("%d",ans);
	
	return 0;
}
