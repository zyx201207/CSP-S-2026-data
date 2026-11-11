#include<bits/stdc++.h>
using namespace std;
const int Maxn=500005;
int n,ans,cnt;
typedef long long ll;
ll m,a[Maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld",a+i);
	sort(a+1,a+1+n);
	for(int i=1,j=1;i<=n;++i){
		m-=cnt*(a[i]-a[i-1]);++cnt;
		while(m<0){m+=a[i]-a[j];++j;--cnt;}
		if (cnt>ans) ans=cnt;
	}
	printf("%d\n",ans);
	return 0;
}
