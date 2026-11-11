#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,M=35;
int a[N],bj[N],sl[M];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	memset(bj,0,sizeof(bj));
	memset(sl,0,sizeof(sl));
	for(int i=1;i<=n;i++){
		int x=a[i],cnt=0;
		while(x){
			if(x%2==1)sl[cnt]++;
			x/=2;cnt++;
		}
	}
	int ans=0,sum=0;
	for(int i=30;i>=0;i--)if(sl[i]>=m){
		sum++;
		for(int j=1;j<=n;j++)if(a[j]&(1<<i))bj[j]++;
		int res=0;
		for(int j=1;j<=n;j++)if(bj[j]>=sum)res++;
		if(res<m)break;
		ans+=(1<<i);
	}
	printf("%lld\n",ans);
	return 0;
}
