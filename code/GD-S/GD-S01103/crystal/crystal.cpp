#include<bits/stdc++.h>
#define int long long 
using namespace std;
//bool ST;
int n,k,a[500005],qz[500005],ans;
//bool ED;
signed main(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) qz[i]=(qz[i-1]+a[i]);
	for(int i=1;i<=n;i++){
		int l=1,r=i,jl=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]-(qz[i]-qz[mid-1])<=k) jl=mid,r=mid-1;
			else l=mid+1;
		}
		if(jl!=-1) ans=max(ans,i-jl+1);
	}
//	cerr<<"Static Memory: "<<((int)((&ED)-(&ST)))*1.0/1024/1024<<".MB\n";
	return printf("%lld\n",ans),0;
}
/*
g++ crystal.cpp -o cmd.exe -O2 -std=c++14 -static -Wall -Wextra
*/
