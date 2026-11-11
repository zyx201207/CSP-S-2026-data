#include<bits/stdc++.h>
using namespace std;
const int MAXX=5e5+5;
int n,ans;
long long m,a[MAXX],s[MAXX];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d",&n);
	scanf("%lld",&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=n;i>=1;i--){
		if(s[i]>=a[i]*i-m){
			ans=i;
			break;
		}
	}
	printf("%d",ans);
	return 0;
}
