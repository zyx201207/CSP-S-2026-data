#include <bits/stdc++.h>
using namespace std;
#define int long long
long long  n,m;
int cp[500005];
long long sum[500005];
int read(){
	int g = 0,f = 1;
	char h = getchar();
	while(h<'0'||h>'9'){
		if(h == '-'){
			f = -1;
		}
		h = getchar();
	}
	while(h>='0'&&h<='9'){
		g*=10;
		g+=(h-'0');
		h = getchar();
	}
	return f*h;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i = 1;i<=n;i++){
		scanf("%lld",&cp[i]);
	}
	sort(cp+1,cp+n+1);
	long long ans = 0;
	for(int i = 1;i<n;i++){
		ans+=(cp[n]-cp[i]);
	}
	int ug = n;
	sum[n] = ans;
	if(ans<=m){
		cout<<n;
		return 0;
	}
	for(int i = n-1;i>0;i--){
		sum[i] = sum[i+1]-(cp[i+1]-cp[i])*(i);
	}
	long long  kk = -1;
	for(int i = 1;i<=n;i++){
		long long  keys = sum[i]-m;
		long long  *bc = lower_bound(sum+1,sum+i+1,keys);
		long long  gi = bc-sum;
		kk = max(i-gi+1,kk);
	}
	printf("%lld",kk);
	
}
