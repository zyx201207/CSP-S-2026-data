#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=5e5+5;
ll m,n,a[N],s[N],ans=0,slkt;
int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n); ll t=a[2]-a[1];bool f=1;
	for(int i=1;i<=n;i++){
		if(a[i]-a[i-1]!=t){f=0;break;} 
	}
	if(f){
		ll num=t; 
		while(m>=num&&ans<n){
			m-=num;ans++;num+=t;
		}
		printf("%lld",min(ans+1,n));return 0;
	}
	for(int i=n;i>=1;i--){
		ll j=i,x=m,cnt=0;
		while(x&&j>0){
			if(x>=a[i]-a[j]) x=x-(a[i]-a[j]),cnt++;
			else break;
			j--;
		}
		ans=max(ans,cnt);
	}
	printf("%lld",ans);
	return 0;
}
