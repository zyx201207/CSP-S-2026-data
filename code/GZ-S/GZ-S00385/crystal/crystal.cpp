//GZ-S00385
//张哲铭
//毕节梁才学校
#include<bits/stdc++.h>
#define int long long
using namespace std;
/*
考虑用维护有序的区间 
还要求 
Oct31==Dec25?
*/
int n,m;
int a[500000+10];
int s;
int ma;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1,j=1;i<=n;i++){
		while(j+1<=n&&s+(a[j+1]-a[j])*(j-i+1)<=m)s+=(a[j+1]-a[j])*(j-i+1),j++;//?
//		printf("====%lld\n",j);
		ma=max(ma,j-i+1);
		s-=a[j]-a[i];
		j=max(j,i);
	}
	printf("%lld\n",ma==1?0:ma);

	return 0;
}
