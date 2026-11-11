#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+100;
int n,m;
int a[N],sum[N];
int l,r;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int ma=-1e9;
	l=1,r=1;
	while(l<=r&&r<=n){
		int k=sum[r]-sum[l-1];
		int cnt=r-l+1;
		if(a[r]*cnt-k<=m){
			ma=max(ma,cnt);
//			cout<<l<<" "<<r<<" "<<ma<<endl;
			r++;
		}else{
			l++;
		}
	}
	printf("%lld",ma);
	return 0;
}
