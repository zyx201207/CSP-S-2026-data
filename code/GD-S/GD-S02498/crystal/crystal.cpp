#include <bits/stdc++.h>
using namespace std;
long long n,l,r;
long long m,ans=1,cnt,sum;
long long a[500010],b[500010];
bool c=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){c=0;}
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i-1] = a[i]-a[i-1];
	}
	l=1;r=1;cnt=b[1],sum=b[1];
	while(l<=r&&r<=n){
		if(cnt<=m){
			r++;
			sum+=b[r];
			cnt+=(r-l+1)*b[r];
			ans = max(r-l+1,ans);
		}
		else{
			cnt-=sum;
			sum-=b[l];
			l++;
		}
	}
	printf("%lld",ans);
	return 0;
}
