#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+114514;
int n,a[N],sum[N],ans;
char c[N];
signed main(){
 	freopen("string.in","r",stdin);
 	freopen("string.out","w",stdout);
 	
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i],sum[i]=sum[i-1]+a[i];
	int l=1,r=n,mid=sum[n]/2,lst;
	while(l<=r){
		if(l==r){
			cout<<ans<<"\n";
			return 0;
		}
		if(c[l]!=c[r]){
			ans+=min(a[l],a[r]);
			if(a[l]<=a[r])a[r]-=a[l],l++;
			else a[l]-=a[r],r--;
		}else{
			if(a[l]>=a[r])a[l]-=a[r],r--;
			else a[r]-=a[l],l++;
		}
	}
	return 0;
}
//luogu 991587
//genshin impact
// T2 做的时间比 T1 短  /ll
//太菜了 qwq 40 min 才写完 T1 T2 /ll 
