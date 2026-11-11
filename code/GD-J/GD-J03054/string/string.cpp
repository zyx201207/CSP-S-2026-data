#include <bits/stdc++.h>
#define int long long
using namespace std;
int nouse=1e18;
constexpr int N=2e5+7;
int n,res,finals,sm,a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		finals+=a[i];
		cin>>c[i];
	}
	sm=finals;
	if(finals%2==0){
		finals/=2;
	}else{
		finals=(finals-1)/2;
	}
	int lidx=0,ridx=n,id=a[n];
	int sum=0;
	while(sum<finals){
		lidx++;
		int need=a[lidx];
		if(sum+a[lidx]>finals){
			int lft=finals-sum;
			int rgh=a[lidx]-lft;
			if(lft<=rgh){
				break;
			}else{
				need=lft-rgh;
			}
		}
		int cipp=0;
		while(cipp<need){
			if(c[lidx]==c[ridx]){
				if(a[lidx]-cipp>=id){
					cipp+=id;
					ridx--;
					id=a[ridx];
				}else{
					id-=a[lidx]-cipp;
					cipp=a[lidx];
				}
			}else{
				if(a[lidx]-cipp>=id){
					cipp+=id;
					res+=id;
					ridx--;
					id=a[ridx];
				}else{
					res+=a[lidx]-cipp;
					id-=a[lidx]-cipp;
					cipp=a[lidx];
				}
			}
		}
		sum+=a[lidx];
	}
	printf("%lld\n",res);
	return 0;
}

