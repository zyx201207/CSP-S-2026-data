#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,ans=1,pos;
ll m,a[N],cnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;++i){
		cnt+=(a[i]-a[i-1])*(i-pos-1);
		while(cnt>m)cnt-=a[i]-a[++pos];
		ans=max(ans,i-pos);
	}
	printf("%d",ans);
	return 0;
}

