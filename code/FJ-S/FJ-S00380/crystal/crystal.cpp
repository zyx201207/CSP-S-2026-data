#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500007];
int prv[500007];
int l,r;
bool cmp(int x,int y){
	return x>y;
}
bool check(int k){
	int mn=LLONG_MAX;
	for(int i=1;i+k-1<=n;i++){
		mn=min(mn,k*a[i]-(prv[k+i-1]-prv[i-1]));
	}
	return mn<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)prv[i]=prv[i-1]+a[i];
	l=0,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l<<endl;
}
