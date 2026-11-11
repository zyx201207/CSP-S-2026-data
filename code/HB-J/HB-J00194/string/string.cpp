#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n;
ll a[N],ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%lld %c",&a[i],&c[i]);
	int L=1,R=n;
	while(L<R){
		ll dt=min(a[L],a[R]);
		if(c[L]!=c[R]) ans+=dt;
		a[L]-=dt;
		a[R]-=dt;
		if(!a[L]) ++L;
		if(!a[R]) --R;
	}
	printf("%lld",ans);
	return 0;
}
