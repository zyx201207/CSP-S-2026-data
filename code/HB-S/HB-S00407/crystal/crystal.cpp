#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxn=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	if (n<=5000){
		sort(a+1,a+1+n);
		for (int i=n;i>=2;i--){
			long long l=i-1,ans=1,opo=0;
			while(l>=1){
				if (l>=1&&a[i]-a[l]+opo<=m){
					ans+=1;
					opo+=a[i]-a[l];
					l--;
				}else break;
			}
			maxn=max(maxn,ans);
		}
		cout<<maxn;
	}else{
		long long p=abs(a[2]-a[1]);
		cout<<min(n,m/p);
	}
	return 0;
}
