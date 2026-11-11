#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long b[200005],ans=0;
char c[200005],d[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	int lb=0;
	long long r=0;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
		if(c[i]!=d[lb]){
			b[++lb]=a[i];
			d[lb]=c[i];
		}else{
			b[lb]+=a[i];
		}
	}
	r=lb;
	long long l=1;
	while(l<r){
		if(d[l]==d[r]){
			if(b[l]==b[r]){
				l++;
				r--;
			}else if(b[l]>b[r]){
				b[l]=b[l]-b[r];
				r--;
			}else{
				b[r]=b[r]-b[l];
				l++;
			}
		}else{
			if(b[l]==b[r]){
				ans=ans+b[l];
				l++;
				r--;
			}else if(b[l]>b[r]){
				ans=ans+b[r];
				b[l]=b[l]-b[r];
				r--;
			}else{
				ans=ans+b[l];
				b[r]=b[r]-b[l];
				l++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
