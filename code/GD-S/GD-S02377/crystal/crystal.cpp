#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long s[500010];
int n;
long long m;
bool check(int len){
	for(int i=len;i<=n;i++){
		if(a[i]*len-(s[i]-s[i-len])<=m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	printf("%d",ans);
	return 0;
}

