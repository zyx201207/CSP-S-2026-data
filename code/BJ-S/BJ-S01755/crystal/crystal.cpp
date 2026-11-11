#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
long long m,a[500005],qzh[500005];
bool check(int l,int r){
	return (r-l+1)*a[r]-(qzh[r]-qzh[l-1])<=m;
}int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		qzh[i]=qzh[i-1]+a[i];
		int l=1,r=i,mid;
		while(l<r){
			mid=(l+r-1)>>1;
			if(check(mid,i))r=mid;
			else l=mid+1;
		}ans=max(ans,i-l+1);
	}printf("%d\n",ans);
	return 0;
}