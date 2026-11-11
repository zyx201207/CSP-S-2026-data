#include <bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	long long vis=m;
	int ans=0;
	a[n+1]=a[n];
	for(int i=n,j=n;i>=1;i--){
		vis+=1ll*(i-j)*(a[i+1]-a[i]);
		while(j>=1){
			if(vis-(a[i]-a[j])>=0){
				vis-=a[i]-a[j];
				j--;
			}
			else break;
		}
		ans=max(ans,i-j);
	}
	printf("%d",ans);
	return 0;
}
