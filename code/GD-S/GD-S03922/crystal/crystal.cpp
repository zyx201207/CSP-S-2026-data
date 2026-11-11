#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
int ans;
int sum[N];
bool check(int x,int mid){
//	printf("%lld %lld\n",(mid-x+1)*a[mid],(sum[mid]-sum[x-1]));
	return (mid-x+1)*a[mid]-(sum[mid]-sum[x-1])<=m;
}
int find(int x){
	if(x==n) return n;
//	printf("%lld \n",x);
	int l=x-1,r=n+1;
	while(l+1<r){
		int mid=(l+r)>>1;
//		printf("%lld %lld %lld \n",l,r,mid);
		if(check(x,mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
//	printf("%lld\n",l);
	return l;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,find(i)-i+1);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

3

5 8
-3 -1 2 2 7

4

7 5
0 1 1 3 5 6 7

*/
