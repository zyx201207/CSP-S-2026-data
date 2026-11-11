#include <bits/stdc++.h> 
using namespace std;
using ll=long long;
void chkmax(int &x,int y){ if(x<y) x=y; }
const int N=5e5+5;
int n; ll m,a[N],s[N];
void Mutsumi(){
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",a+i);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int res=0;
	for(int i=1;i<=n;i++){
		int l=0,r=i-1,mid;
		while(l<r) mid=l+r+1>>1,mid*a[i]-(s[i-1]-s[i-mid-1])<=m?l=mid:r=mid-1;
		chkmax(res,l+1);
	}
	printf("%d",res);
	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
	while(T--) Mutsumi();
	return 0;
}
