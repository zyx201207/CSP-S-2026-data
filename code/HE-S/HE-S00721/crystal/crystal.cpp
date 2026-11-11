#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n, m, a[N], maxn=-1, minn=1e12+5, ans, t[N];
int lowbit(int x){return x&-x;}
void add(int x, int k){
	for(;x<=n;x+=lowbit(x))t[x]+=k;
	return;
}
int query(int x){
	int res=0;
	for(;x;x-=lowbit(x))res+=t[x];
	return res;
}
bool check(int mid){
	bool flag=0;
	for(int i=1;i+mid-1<=n;i++)
		if(a[i+mid-1]*mid-query(i+mid-1)+query(i-1)<=m)flag=1;
	return flag;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	if(n==1){
		printf("1");
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)add(i,a[i]);
	int l=1, r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1, ans=mid;
		else r=mid;
	}
	printf("%lld",ans);
	return 0;
}
