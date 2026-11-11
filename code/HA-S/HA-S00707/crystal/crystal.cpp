#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,ans=0;
long long m,a[N],k,b[N];
int p=0,i,j;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	k=m;
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(k<=a[mid]*mid-b[mid])r=mid-1;
		else l=mid+1;
	}
	for(int i=l;i<=n;i++){
		k=m;
		for(int j=i-l+1;j>=1;j--){
			if(k<a[i]*(i-j+1)-b[i]+b[j-1]){
				p=1;
				ans=max(ans,i-j);
				break;
			}
		}
		if(p==1)p=0;
		else ans=max(ans,i);
	}
	printf("%d",ans);
	return 0;
}
