#include<bits/stdc++.h>
using namespace std;

namespace YiShengYS{
	
const int cst=5e5+5;
long long n,m,d,nm,ans;
long long a[cst],da[cst];
bool j1;
	
int main(){
	cin>>n>>m;
	j1=0;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		if(i>=2){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]) j1=1;
		}
	}
	if(!j1){
		ans=n;
		d=abs(a[1]-a[0]);
		nm=0;
		if(n&1){
			for(long long i=1;i<=(n>>1);i++){	
				nm+=2*i*d;
				if(nm>m){
					ans=2*i-1;
					break;
				}
			}
		}else{
			for(long long i=1;i<=(n>>1);i++){	
				nm+=(2*i-1)*d;
				if(nm>m){
					ans=2*i-2;
					break;
				}
			}
		}
	}else{
		sort(a,a+n);
		da[0]=a[0];
		for(long long i=1;i<n;i++){
			da[i]=a[i]-a[i-1];
		}
		for(long long i=0;i<n;i++){
			long long lfl=i,rtl=i+1,lfn=da[i],rtn=da[i+1];
			for(long long j=0;j<n;j++){
				if(lfl<0 && rtl>=n){
					ans=n;
					break;
				}
				if(lfl<0 || (rtn<lfn && rtl<n)){
					nm+=rtn;
					rtl++;
					rtn+=da[rtl];
				}else{
					nm+=lfn;
					lfl++;
					lfn+=da[lfl];
				}
				if(nm>m){
					ans=max(ans,j);
					break;
				}
			}
			if(ans>=n) break;
		}
	}
	cout<<ans<<"\n";
	return 0;
}


} 

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	YiShengYS::main();
	return 0;
}
