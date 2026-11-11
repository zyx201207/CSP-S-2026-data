#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n,m,a[N],ans,s[N],xy,maxn,maxi,h,t;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a + 1,a + 1 + n);
	maxn = a[1];
	maxi = 1;
	h = 1;
	for(t = 2;t <= n;t++){
		if(a[t] > maxn){
			xy += (a[t] - maxn) * (t - h);
			maxn = a[t];
		}
		while(xy > m){
			xy -= (maxn - a[h]);
			h++;
		}
		maxi = max(maxi,t - h + 1);
	}
	cout<<maxi;
	return 0;
}
