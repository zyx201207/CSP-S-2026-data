#include<bits/stdc++.h>
#define longlong long long
//#define longlong __int128_t
#define ll (longlong)
namespace NOTLE{
	void NOTLE(){
		std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
		return;
	}
	void NO_TLE(){
//		std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
		return;
	}
}
using namespace std;
bool frein=false,freout=false,refrein=false;
longlong n,a[200010ll],l=1ll,r,ans;
char chs[200010ll];
signed main(){
	NOTLE::NO_TLE();//samples:6
	freopen("string.in","r",stdin),frein=true;
	freopen("string.out","w",stdout),freout=true;
	refrein=(frein and not(freout));
	scanf("%lld",&n);
	if(refrein)	printf("%lld\n",n);
	r=n;
	for(longlong i=1ll;i<=n;i++){
		scanf("%lld",&a[i]);
		if(refrein)	printf("%lld",a[i]);
		chs[i]=' ';
		while(chs[i]==' ' or chs[i]=='\n'){
			scanf("%c",&chs[i]);
			if(refrein)	printf("%c",chs[i]);
		}
		if(refrein)	printf("\n");
	}
	while(l<r){
		if(chs[l]==chs[r]){
			if(a[l]<a[r]){
				a[r]-=a[l];
				a[l]=0ll;
			}
			else{
				a[l]-=a[r];
				a[r]=0ll;
			}
		}
		else{
			if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				a[l]=0ll;
			}
			else{
				ans+=a[r];
				a[l]-=a[r];
				a[r]=0ll;
			}
		}
		if(a[l]<=0ll)	l++;
		if(a[r]<=0ll)	r--;
	}
	printf("%lld\n",ans);
	return 0;
}
