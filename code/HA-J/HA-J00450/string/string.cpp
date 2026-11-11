#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,a[N],ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld %c",&a[i],&c[i]);
	ll l=1,r=n;
	while(l<r){
		if(a[l]>=a[r]){
			if(c[l]!=c[r])ans+=a[r];
			a[l]-=a[r];
			a[r]=0;
			r--;
		}
		else{
			if(c[l]!=c[r])ans+=a[l];
			a[r]-=a[l];
			a[l]=0;
			l++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}

