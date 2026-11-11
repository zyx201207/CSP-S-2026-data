#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=2e5+3;
ll n,a[N],ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::cin >>n;
	for(int i=0;i<n;i++)std::cin >>a[i]>>c[i];
	ll l=0,r=n-1;
	ll l2=a[l],r2=a[r];
	while(l<r){
		if(c[l]!=c[r])ans+=min(l2,r2); 
		if(l2>r2)l2-=r2,r--,r2=a[r];
		else if(l2==r2)l++,r--,l2=a[l],r2=a[r];
		else r2-=l2,l++,l2=a[l];
	}
	printf("%lld",ans);
}
