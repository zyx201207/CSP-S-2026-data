#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+10;
int n,m,a[MAXN],f[2005][2005];
int cmp(int x,int y){
	return x>y;
}
main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n,cmp);
	int ans=0;
	if(n<=2000){
		for(int lenth=1;lenth<=m;lenth++){
			for(int l=1;l+lenth-1<=n;l++){
				int r=l+lenth-1;
				if(lenth==1) f[l][r]=a[l];
				else f[l][r]=f[l][r-1]&a[r];
			}
		}
		for(int i=1;i+m-1<=n;i++){
			ans=max(ans,f[i][i+m-1]);
		}
	}else if(m==n-1){
		int ll=a[2];
		for(int i=2;i<n;i++) ll=ll&a[i];
		ans=max(ll&a[1],ll&a[n]);
	}else{
		int fla=1;
		for(int i=1;i<=n;i++){
			if(a[i]+1!=(a[i]+1)&(-(a[i]+1))) fla=0;
		}
		if(fla){
			ans=a[m];
		}else{
			int ll=a[1];
			for(int i=1;i<=m;i++) ll=ll&a[i];
			ans=ll;
		}
	}
	printf("%lld",ans);
	return 0;
} 
