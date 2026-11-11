#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,ans=-1,tmp,cnt,pos;
int i,j;
bool flag=0;
int a[N],s[N];
bool cmp(int a,int b){
	return a<b;
}
bool check(int mid){
	for(int i=1;i+mid<=n;i++){
		if(mid*a[i+mid-1]-s[i+mid-1]+s[i-1]<=m) return true;
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}	
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	printf("%lld",l);
	return 0;
}
