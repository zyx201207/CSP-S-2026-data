#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],b[N];
int ans;
signed main(){
	freopen("crystal.in" ,"r",stdin );
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	n--;
	for(int i=1;i<=n;i++)
		a[i]=a[i+1]-a[i];
	for(int i=1;i<=n;i++)
		a[i]+=a[i-1];
	for(int i=1;i<=n;i++)
		b[i]=b[i-1]+a[i];
	for(int l=1,r=1;r<=n;l++){
		while(((r-l+1)*a[r]-(b[r-1]-b[l-1]))<=m && r<=n)r++;
		if(r>n)ans=max(ans,n-l+1);
		else ans=max(ans,r-l+1);
	}
	printf("%lld",ans);
	return 0;
} 
