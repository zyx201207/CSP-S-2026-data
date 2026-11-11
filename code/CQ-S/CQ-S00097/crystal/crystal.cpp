#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e6 + 10;
int n;
ll m,a[N];
ll k;
ll len[N],lenn[N];
ll ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i = 1;i <= n;i++){scanf("%lld",&a[i]);}
	sort(a + 1,a + n + 1);
	len[1] = 0;
	for(int i = 2;i <= n;i++) len[i] = len[i - 1] + (a[i] - a[i - 1]);
	for(int i = 1;i <= n;i++) lenn[i] = lenn[i - 1] + len[i];
	for(int i = 1;i <= n - 1;i++) lenn[n + i] = lenn[n + i - 1] + len[n];
	for(ll i = 1;i <= n;i++){
		if(len[i] == 0) continue;
		for(ll j = i - 1;j <= i + 1;j++){
			if(len[i] * (i - 1) - lenn[j] <= m){
				ans = max(ans,(2 * i) - (j + 1));
				break;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
