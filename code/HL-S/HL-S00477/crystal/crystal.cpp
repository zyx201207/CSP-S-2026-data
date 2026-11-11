#include<bits/stdc++.h>

using namespace std;
long long n;
long long m;
const int N=5e5+100;
long long ans;
long long a[N];
bool cmp(long long a,long long b) {
	return a<b;
}
unordered_map<long long,long long> mp;
void dfs(long long t,long long mm,long long nn,long long x) {
	for(int i=t-1;i>=1 && nn<=n;i--) {
		if((a[t]-a[i])*mp[a[i]]+mm<=m) {
			mm+=(a[t]-a[i])*mp[a[i]];
			nn+=mp[a[i]];
		}
		else {
			nn+=(m-mm)/(a[t]-a[i]);
			break;
		}
	}
	printf("%d\n",nn);
	ans=max(ans,nn);
}
bool f1=1;
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		if(i>2 && (a[i]-a[i-1]!=a[i-1]-a[i-2])) f1=false;
		mp[a[i]]++;
	}
	sort(a+1,a+n+1);
	long long x=unique(a+1,a+n+1)-a-1;
	if(!f1) for(int i=1;i<=x;i++) {
		dfs(i,0,mp[a[i]],x);
//		printf("%d\n",ans);
		if(ans==n) break;
	}
	else {
		dfs(x,0,mp[a[x]],x);
//		printf("YES");
	}
	printf("%lld",ans);
//	printf("%d%lld",x,a[1]);
	return 0;
}
