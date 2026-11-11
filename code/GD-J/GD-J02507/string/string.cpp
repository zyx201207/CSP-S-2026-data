#include<bits/stdc++.h>
using namespace std;
long long n,ans,l,r,a[200005];
char x[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cin>>x[i];
	}
	l=1;
	r=n;
	while(l<=r){
		if(a[l]==a[r]){
			if(x[l]!=x[r]){
				ans+=a[l];
			}
			l++;
			r--;
		}else{
			if(x[l]!=x[r]){
				ans+=min(a[l],a[r]);
			}
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else{
				a[r]-=a[l];
				l++;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
