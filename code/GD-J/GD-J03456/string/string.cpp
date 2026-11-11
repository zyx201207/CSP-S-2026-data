#include<bits/stdc++.h>
using namespace std;
long long ans;
int n;
int a[200001];
char c[200001];
int l=1,r;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	r=n;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
	}
	while(1){
		if(a[l]>a[r]){
			ans+=a[r]*(c[l]!=c[r]);
			a[l]-=a[r];
			r--;
		}else if(a[l]<a[r]){
			ans+=a[l]*(c[l]!=c[r]);
			a[r]-=a[l];
			l++;
		}else{
			ans+=a[l]*(c[l]!=c[r]);
			a[r]=a[l]=0;
			l++,r--;
		}
		if(l>=r) break;
	}
	printf("%lld",ans);
	return 0;
}

