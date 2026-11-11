#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
char c[200010];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
	}
	int l=1,r=n;
	while(l<=r){
//		cout<<l<<'!'<<r<<'!'<<ans<<'-';
		if(c[l]!=c[r]){
			if(a[l]==a[r]){
				ans+=a[l];
				l++;r--;
			}else if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}else if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}else{
			if(a[l]==a[r]){
				l++;r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
