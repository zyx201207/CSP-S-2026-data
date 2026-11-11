#include<bits/stdc++.h>
using ll=long long;
using namespace std;
const int N=5e5+10;
int n,ans;
ll p[N],a[N],m,cnt;
int bot,top;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bot=1,top=0;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		cnt+=(a[i]-a[i-1])*(top-bot+1);
		p[++top]=a[i];
		while(bot<=top&&cnt>m)
			cnt-=a[i]-p[bot++];
		ans=max(ans,top-bot+1);}
	printf("%d\n",ans);
	return 0;
}
