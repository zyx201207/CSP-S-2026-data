#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,m;
int a[maxn],f[maxn],sum[maxn];
int ask(int l,int r){
	return sum[r]-sum[l-1]-(l-1)*(a[r]-a[l-1]);
}
bool check(int mid){
	for(int i=1;i+mid-1<=n;++i){
		if(ask(i,i+mid-1)<=m){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		f[i]=a[i]-a[i-1];
	} 
	for(int i=1;i<=n;++i){
		sum[i]=sum[i-1]+f[i]*i;
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%d",r+1);
	return 0;
} 
/*5 8
-3 -1 2 2 7*/
