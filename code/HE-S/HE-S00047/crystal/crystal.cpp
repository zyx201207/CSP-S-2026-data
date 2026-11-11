#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+5;
ll n,m,a[N],s[N];
bool check(int k){
	for(int i=k;i<=n;i++){
		if(a[i]*k-(s[i]-s[i-k])<=m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int L=1,R=n,mid,ans;
	while(L<=R){
		mid=(L+R)>>1;
		if(check(mid)){
			ans=mid;
			L=mid+1;
		}else{
			R=mid-1;
		}
	}
	printf("%d",ans);
	return 0;
}
