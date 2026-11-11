#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=510000;
int n;
long long m,a[N],s[N];
bool check(int x){
	for(int i=x;i<=n;i++){
		if(s[i]-s[i-x]<=a[i]*x&&a[i]*x-(s[i]-s[i-x])<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n,mid;
	while(l<r){
		mid=(l+r+1)>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	return 0;
}
