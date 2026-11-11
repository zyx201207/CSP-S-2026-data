#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,ans;
ll m,a[N],c[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)c[i]=c[i-1]+a[i];
	int l=1;
	for(int i=1;i<=n;i++){
		while((i-l)*a[i]-(c[i]-c[l])>m)l++;
		ans=max(i-l+1,ans);
	}
	printf("%d",ans);
	return 0;
}