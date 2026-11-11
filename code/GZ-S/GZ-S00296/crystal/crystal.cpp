//GZ-S00296  遵义市新浦新区滨湖中学 范曾
#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],num[1000005]= {},ans1=0,ans2=0,x=0;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	sort(a+0,a+n);
	for(long long s=0; s<n; s++) {
		for(long long i=s; i<n; i++) {
			x++;
			for(long long j=s; j<i; j++) {
				if(a[i]-a[j]>=0){
					num[x]+=(a[i]-a[j]);
				}else{
					num[x]+=(a[j]-a[i]);
				}				
			}
			if(num[x]==m) {
				ans1=max(ans1,i-s+1);
			}else if(num[x]<m){
				ans1=max(ans1,i-s+1);
			}
		}
	}
	cout<<ans1;
	return 0;
	fclose(stdin);
	fclose(stdout);
}	


