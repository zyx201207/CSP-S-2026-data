#include<bits/stdc++.h> 
using namespace std;
int n,ans=1;
long long m,a[500002],num,ber;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=n;i>=2;i--) {
		num=0; ber=0;
		for(int j=i-1;j>=1;j--){
			num=a[i]-a[j];
			ber=ber+num;
			if(ber>m)
				break;
			if(i-j+1>ans)
				ans=i-j+1;
		}
	}
	printf("%d",ans);
	return 0;
}
