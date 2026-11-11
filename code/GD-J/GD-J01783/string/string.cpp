#include<bits/stdc++.h>
using namespace std;
int n,k;
long long ans=0,a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	k=1; b[0]='0';
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[k],&b[k]);
		while(b[k]==b[k-1]){
			a[k-1]+=a[k];
			k--;
		}
		k++;
	}k--;
	int l=1,r=k;
	while(l<r){
		if(a[l]>a[r]){
			if(b[l]!=b[r]){
				b[r]=b[l];
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}else if(a[l]==a[r]){
			if(b[l]!=b[r]){
				b[r]=b[l];
				ans+=a[r];
			}
			l++; r--;
		}else{
			if(b[l]!=b[r]){
				b[l]=b[r];
				ans+=a[l];
			}
			a[r]-=a[l];
			l++;
		}	
	}
	printf("%lld",ans);
	return 0;
}
