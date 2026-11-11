#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ultra __int128
int n,m;
int a[1000001];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a + 1,a + 1 + n);
	__int128 need = 0;
	int ans = 0,op = a[1],ps = 1;
	for(int i = 1;i <= n;i++){
		while((a[i] - op) * (i - ps) + need > m){
			need -= (op - a[ps]);
			ps++;
			if(ps == i){
				op = a[i];
			}
		}
		need += (a[i] - op) * (i - ps);
		ans = max(ans,i - ps + 1);
		op = a[i];
		//cout<<a[i]<<" "<<ps<<" "<<need<<endl;
	}
	printf("%lld",ans);
	return 0;
}

