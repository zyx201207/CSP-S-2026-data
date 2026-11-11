//GZ-S00394 毕节梁才学校 赵纤茹
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,m;
LL a[500000+10];
LL s[500000+10]; 

bool check(int x,int t){
	LL num=t-1-x+1;
	LL sum=num*a[t]-(s[t-1]-s[x-1]);
	if(sum<=m) return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i+1;
		while(l<r){
			int mid=(l+r)/2;
			if(check(mid,i)) r=mid;
			else l=mid+1;
		}
		if(l==i+1) continue;
		else ans=max(ans,i-l+1); 
	} 
	printf("%d",ans);
	return 0;
} 
