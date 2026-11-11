#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[1000100];
long long b[1001000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	int ma=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(a[i]*mid-(b[i]-b[i-mid])<=m)l=mid+1;
			else r=mid-1;
		}
		ma=max(ma,l-1);
	}
	printf("%d",ma);
	return 0;
}
