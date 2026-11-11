#include<bits/stdc++.h>
using namespace std;
int n,k=INT_MIN;
long long m,a[500010],sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		sum=m;
		for(int j=i-1;j>=1;j--){
			if(sum<a[j]){
				k=max(k,i-j+1);	
				break;
			}else sum=sum+a[j]-a[i];
		}
	}
	printf("%d",k);
	return 0;
}
