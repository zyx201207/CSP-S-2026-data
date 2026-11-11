#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],maxn,f[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) f[i]=f[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)>>1;
			int w=a[i]*(i-mid+1);
			int c=f[i]-f[mid-1];
			if(abs(w-c)<=m) r=mid;
			else l=mid+1;
		}
		maxn=max(maxn,i-l+1);
	}
	cout<<maxn;
	return 0;
}
