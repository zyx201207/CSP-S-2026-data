#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long ans;
long long sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int j=1;j<=n;j++){
		if(m<=0) break;
			for(int i=1;i<=n;i++){
			if(m>=a[i+1]-a[i]){
				while(a[i]<a[i+1]){
					a[i]++;
					m--;
				}
				sum++;
			}
			else{
				break; 
			} 
		}	
	}
	for(int i=1;i<=n;i++){
		if(a[i]==sum){
			ans++;
		}
	}
	printf("%lld",ans);
	return 0;
}
