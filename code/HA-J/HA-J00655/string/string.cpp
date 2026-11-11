#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N=2e5+5;
int n;
ll a[N],sum,ans;
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);cin>>c[i];
		sum+=a[i];
	}
	int l=1,r=n;
	while(l<r-1){
		if(c[l]==c[r]){
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else{
				l++;r--;
			}
		}else{
			if(a[l]<a[r]){
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}else if(a[l]>a[r]){
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}else{
				ans+=a[l];
				l++;r--;
			}
		}	
	}
	if(l==r-1){
		if((a[l]+a[r])%2==0){
			if(c[l]!=c[r])ans+=min(a[l],a[r]);//(a[l]+a[r])-max(a[l],a[r]);	
		}else{
			if(c[l]!=c[r])ans+=min(a[l],a[r]);//(a[l]+a[r]-1)-max(a[l],a[r])+1;
		}
	}
	printf("%lld",ans);
	return 0;
}
