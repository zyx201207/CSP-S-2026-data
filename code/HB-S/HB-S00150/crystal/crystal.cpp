#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,ans=1;
ll m,a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
	for(int i=2;i<=n;++i){
		if(a[i]-a[i-1]>m) continue;
		int L=1,R=i-1;
		while(L<R){
			int M=L+((R-L)>>1);
			a[i]*(i-M)-(s[i-1]-s[M-1])>m?L=M+1:R=M;
		}
		ans=max(ans,i-R+1);
	}
	printf("%d",ans);
	return 0;
}
