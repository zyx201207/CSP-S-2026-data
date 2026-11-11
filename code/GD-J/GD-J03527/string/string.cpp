#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
char c[200005];
int main(){
	//freopen("string5.in","r",stdin);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;scanf("%lld",&n);
	ll l=1,r=n,ans=0;
	for(int i=1;i<=n;i++) scanf(" %lld %c",a+i,c+i);
	while(l<=r){
		if(a[l]<a[r]){
			if(c[l]!=c[r]) ans+=a[l];
			a[r]-=a[l];
			l++;
		}
		else if(a[r]<a[l]){
			if(c[l]!=c[r]) ans+=a[r];
			a[l]-=a[r];
			r--;
		}
		else{
			if(c[l]!=c[r]) ans+=a[l];
			a[l]=0;
			a[r]=0;
			l++;
			r--;
		}
	}
	printf("%lld",ans);
	return 0;
}
