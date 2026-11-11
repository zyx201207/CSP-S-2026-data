#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],use=0,ans=1,u[500005],o;
bool p=1,q=1;
int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i==2){
			o=a[2]-a[1];
		}
		if(i!=1&&a[i]-a[i-1]!=o){
			q=0;
		}
	}
	if(q){
		long long c=1,i=1;
		while(m-o*c>=0){
			m=m-(c*o);
			c++;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n);
	u[1]=0;
	for(long long i=2;i<=n;i++){
			use=use+(a[i]-a[i-1])*(i-1);
			u[i]=use;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i-1;j>=1;j--){
			if(u[i]-u[j]-(j-1)*(a[i]-a[j])<=m){
				ans=max(ans,i-j+1);	
			}
			else break;
		}
	}
	cout<<ans;
	return 0;
	
} 
