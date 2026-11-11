//GZ-S00146 贵阳市第九中学 向一坤 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+9;
int n,ans=0;
ll m,a[N],s[N];
void slove(ll x){
	int l=1,r=x;
	while(l<r){
		int mid=(l+r)>>1;
		if(a[x]*(x-mid+1)-(s[x]-s[mid-1])<=m) r=mid;
		else l=mid+1;
	}
	ans=max(ans,int(x-l+1));return ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;++i){
		slove(i);
	}
	printf("%d",ans);
	return 0;
} //15:05 AC
//难崩一开始s[i]是在sort前算的卡了十几分钟 
