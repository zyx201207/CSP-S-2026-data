#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+50;
int n;
ll m;
ll a[N],f[N];
int ans;
bool check(int x,int p){
	return m-(a[p]*1ll*(p-x+1)-(f[p]-f[x-1]))>=0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)f[i]=f[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=0,r=i;
		while(l+1<r){
			int mid=(l+r)>>1;
			if(check(mid,i))r=mid;
			else l=mid;
		} 
		ans=max(ans,i-r+1);
	}
	printf("%d",ans);
	return 0;
} 
