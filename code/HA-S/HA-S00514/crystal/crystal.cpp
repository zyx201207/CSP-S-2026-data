#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a1[500005],a2[500005],ans,a3[500005],l=1;
int er(int x){
	int r=1,l=x,mid=(r+l)/2,m1=0;
	while(r<l){
		mid=(r+l)/2;
		m1=(a2[x-1]-a2[mid-1])-(x-mid)*a1[x]+m;
		if(m1>0){
			l=mid;
		}
		else if(m1==0){
			while(a1[mid-1]==a1[mid] && mid>=2) mid--;
			return x-mid;
		}
		else r=mid+1;
	}
	if((a2[x-1]-a2[r-1])-(x-r)*a1[x]+m>0) return x-r;
	else return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int p=1; p<=n; p++){
    	scanf("%lld",&a1[p]);
	}
	sort(a1+1,a1+n+1);
	for(int p=1; p<=n; p++){
		a2[p]=a2[p-1]+a1[p];
	}
	for(int p=2; p<=n; p++){
		int u=er(p)+1;
		ans=max(ans,u);
	}
	printf("%lld",max(ans,l));
	return 0;
} 
