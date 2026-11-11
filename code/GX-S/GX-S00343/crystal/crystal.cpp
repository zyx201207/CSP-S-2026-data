#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#define LL long long
using namespace std;
int n,ans=0;
LL fsum[514514],m,arr[514514];
int main(){	// except:O(nlogn)
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",arr+i);
	}
	sort(arr+1,arr+n+1);
	fsum[0]=0;
	for(int i=1;i<=n;i++){
		fsum[i]=fsum[i-1]+arr[i];
	}
	for(int i=2;i<=n;i++){
		int l=1,r=i,mid;
		while(l<=r){
			mid=(l+r)/2;
			int k=i-mid+1;
			LL exc=k*arr[i];
			LL sm=fsum[i]-fsum[mid-1];
			if(exc-sm>m){	
				l=mid+1;
			}else if(exc-sm==m){
				ans=max(ans,k);
				break;
			}else {
				r=mid-1;
				ans=max(ans,k);
			}
		}
	}
	printf("%d",ans);
	return 0;
}
// finished at 14:57
// To wyx: I love you
