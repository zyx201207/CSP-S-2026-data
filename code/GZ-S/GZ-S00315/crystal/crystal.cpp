//GZ-S00315 冉哲睿 六盘水市第三中学 
#include<bits/stdc++.h>
using namespace std;
int n,maxn;
long long m,a[500001],b[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i=1;i<n;i++){
		long long t=m;
		for(int j=1;j<=n-i;j++){
			if(t>=j*b[i+j]){
				t-=j*b[i+j];
			}else{
				maxn=max(maxn,j);
				break;
			}
		}
	}
	printf("%d",maxn);
	return 0;
}
