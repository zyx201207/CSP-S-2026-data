#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,ans=1;
ll m,a[N],s[N],sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
    	scanf("%lld",&a[i]);
	}	
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=a[i]-a[i-1];
	}
	int l=1;
	sum=0;
	for(int r=2;r<=n;r++){
		while((ll)(sum+(r-l)*s[r])>m&&l<r){
			sum-=a[r-1]-a[l];
			++l;
		}
		ans=max(ans,r-l+1);
		sum+=(ll)(r-l)*s[r];
	}
	printf("%d",ans);
	return 0;
}
