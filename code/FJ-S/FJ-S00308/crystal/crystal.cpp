#include <bits/stdc++.h>
using namespace std;
using LL=long long;
const int maxn=5e5+10;
int n;
LL m, a[maxn];
LL sum[maxn];
LL ans=1;
/*void cs(LL _){
	cout << "----------" << _ << "----------\n";
	return ;
}*/
LL f(LL x, LL i){
	LL res=(LL)x*a[i];
	res+=sum[i-x-1]-sum[i-1];
	return res;
}
LL search(LL i){
	LL l=1, r=i-1;
	while(l<=r){
		LL mid=(l+r)>>1;
		if(f(mid, i)<=m)l=mid+1;
		else r=mid-1;
	}
	return l-1;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=a[i]+sum[i-1];
	}
//	cs(1);
	for(LL i=2;i<=n;i++){
		LL k=search(i);
//		cs(i);
		k+=1;
		if(k>ans)ans=k;
	}
	cout << ans << '\n';
	return 0;
}
/*
把a[j]->a[i]要a[i]-a[j]
把i的左边第k个变为a[i]要a[i]-a[i-k]
把i的左边k个中间全变成a[i] 要:k*a[i]+sum[i-k-1]-sum[i-1]
k<i;可以同化k+1个 
这个式子在k增大时单调递增
 
于是：ans=max(ans[i])
ans[i]=k+1，其中k=最大p，使得p*a[i]+sum[i-p-1]-sum[i-1]<=m 


*/
