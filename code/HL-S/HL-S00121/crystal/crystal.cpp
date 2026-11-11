#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+5;
int n,m,a[N],flag[N],tot,sum=1,from=1,ans=1;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) flag[i]=a[i]-a[i-1];
	for(int i=2;i<=n;i++){
		tot=tot+sum*flag[i];
		sum++;
		while(tot>m&&from<i){
			tot=tot-(a[i]-a[from]);
			from++;
			sum--;
		}
		ans=max(sum,ans);
	}
	printf("%lld",ans);
	return 0;
}

