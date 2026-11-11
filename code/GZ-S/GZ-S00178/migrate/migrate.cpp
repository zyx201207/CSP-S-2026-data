//GZ-S00178 贵阳市第一中学 申智美 
#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long a[2000005];
long l=1,r=n;
bool ef(long long x){
	int f=0;
	while(1){
		long long mid=(l+r)/2;
		if(a[mid]==x){
			f=1;
			return 1;
		}
		else if(a[mid]>x){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
		if(r<l) break;
	}
	if(f==0) return 0;
}
bool f(long long x,long long y){
	long long m=d-1,s=y-x;
	if(s%d!=m) {
		return 0;
	}
	if(s<=d) return 0;
	if(s%d==0) return 0;
//	for(long long i=x+d;i<=y;i+=d){
//		if(ef(i)==0){
//			return 0;
//		}
//	}
//	for(long long i=y-d;i>=x;i-=d){
//		if(ef(i)==0){
//			return 0;
//		}
//	} 
//	if(ef(x+m)==0){
//		return 0;
//	}
//	if(ef(y-m)==0){
//		return 0;
//	}
	return 1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int cnt=0;
		cin>>n>>d;
		long long k=n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]>d) k=i-1;
		}
		for(int i=1;i<=k;i++){
			for(int j=i;j<=k;j++){
				if(f(a[i],a[j])) cnt++;
			} 
		}
		cout<<cnt<<endl;
		for(int i=1;i<=n;i++) a[i]=0;
	}
	return 0;
} 
