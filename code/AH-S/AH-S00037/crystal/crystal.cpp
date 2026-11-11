#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],l=1,r,mid,s[500010];
bool check(long long x){
	long long sum=LLONG_MAX;
	for(int i=x;i<=n;i++){
		sum=min(sum,x*a[i]-(s[i]-s[i-x]));
	}
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	r=n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
}
