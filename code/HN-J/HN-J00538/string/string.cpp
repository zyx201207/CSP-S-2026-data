#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
char a[N];
int c[N];
int n,l,r;
long long tot,num,cnt,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&c[i],&a[i]);
		tot+=c[i];
	}
	num=tot/2+tot%2;
	l=1,r=n;
	while((cnt<num||(cnt<=num&&tot%2==0))&&l<=r){
		long long p;
		if(cnt+c[l]>=num&&cnt+c[r]>=num){
			if(tot%2==0) p=num-cnt;
			else p=num-cnt-1;
		}else{
			p=min(c[l],c[r]);
		}
		if(a[l]==a[r]){
			if(c[l]<=c[r]){
				c[r]-=p;
				c[l]=0;
				cnt+=p;
				l++;
			}else{
				c[l]-=p;
				c[r]=0;
				cnt+=p;
				r--;
			}
		}else{
			if(c[l]<=c[r]){
				c[r]-=p;
				c[l]=0;
				cnt+=p;
				ans+=p;
				l++;
				
			}else{
				c[l]-=p;
				c[r]=0;
				cnt+=p;
				ans+=p;
				r--;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
