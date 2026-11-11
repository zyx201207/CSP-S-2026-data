#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
long long a[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	int n;
	long long m;
	scanf("%d%lld",&n,&m);
	
	bool is_specil=true;
	int d;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i==2){
			d=a[2]-a[1];
		}
		if(i>2&&a[i]-a[i-1]!=d){
			is_specil=false;
		}
	}
	
	if(is_specil){
		for(int i=1;i<=n;i++){
			if(i<n&&d*(i*(i-1))/2<=m&&d*(i*(i+1))/2>m){
				printf("%d\n",i);
				return 0;
			}
			if(i==n&&d*(i*(i-1))/2<=m){
				printf("%d\n",n);
				return 0;
			}
		}
	}
	
	sort(a+1,a+n+1);
	for(int len=n;len>=1;len--){
		for(int s=1;s+len-1<=n;s++){
			long long sum=0;
			bool flag=true;
			
			for(int j=s;j<s+len-1;j++){
				sum+=a[s+len-1]-a[j];
				if(sum>m){
					flag=false;
					break;
				}
			}
			if(flag) {
				printf("%d\n",len);
				return 0;
			}
		}
	} 
	return 0;
}
