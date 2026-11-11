#include<bits/stdc++.h>
using namespace std;
long long m,n,a[5000015],ans,i,j;
bool p;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		long long x=m,s=0;
		for(j=1;j<i;j++){
			if(x-(a[i]-a[j])>=0){
				x-=a[i]-a[j];
				s++;				
			}
			else {
				break;
				p=1;
			}
		}		
		ans=max(ans,s+1);
		if(p)break;
	}
	printf("%lld",ans);
	return 0;
}
