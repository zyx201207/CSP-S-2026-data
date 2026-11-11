#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[501000],s[501000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i+1;//l=how many can you choose                (why I'm using English???)
		while(l+1<r){
			int mid=(l+r)/2;
			if(1LL*mid*a[i]-s[i]+s[i-mid]<=m)l=mid;
			else r=mid;
		}
		ans=max(ans,l);
	}
	printf("%d\n",ans);
}
