#include <bits/stdc++.h>
#define int long long
using namespace std;
const  int N=5e5+5;
int a[N],n,m,q[N];
signed main(){
	freopen("cyrstal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	int maxn=-1;int l,r;l=r=0;
	sort(a+1,a+n+1);int k=0;
	for(int i=1;i<=n;i++){q[++r]=a[i];
		int spe=(a[i]-a[i-1])*(r-l)+k;
		while(l<r){
			int u=q[l];
			if(spe>m)spe-=(a[i]-u);
			else break;
			l++;
		}
		k=spe;maxn=max(r-l+1,maxn);
	}
	printf("%lld",maxn);
	return 0;
}
