#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
int n,a[maxn];
char s[maxn];
int sum,ans;
int l,r;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld %c",a+i,s+i);
		sum+=a[i];
	}
	r=n,l=1;
	sum>>=1;
	for(int i=1;i<=sum;++i){
		if(s[l]!=s[r]){
			i+=min(a[l],a[r])-1,ans+=min(a[l],a[r]);//printf("i:%lld ans:%lld al:%lld ar:%lld l:%lld r:%lld\n",i,ans,a[l],a[r],l,r);
			if(a[l]==a[r]){
				l++,r--;
			}
			else {
				if(a[l]>a[r]){
					a[l]-=a[r],r--;
				}else{
					a[r]-=a[l],l++;
				}
			}
		}else{
			a[l]--,a[r]--;
			if(a[l]==0){
				l++;
			}
			if(a[r]==0){
				r--;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
/*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b*/

