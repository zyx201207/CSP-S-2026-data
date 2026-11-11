#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
long long cnt[500005];
bool check(int mid){
	for(int i=mid;i<=n;i++){
		if(cnt[i]-cnt[i-mid]+m>=1ll*mid*a[i]){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cnt[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		cnt[i]+=cnt[i-1];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}
		else{
			r=mid-1;
		}
	}
	printf("%d",r);
	return 0;
}
