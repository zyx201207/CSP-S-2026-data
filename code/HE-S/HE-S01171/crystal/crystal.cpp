#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=1e8;
bool cmp(LL a,LL b){
	if(a!=b) return a>b;
}
LL n,m;
LL q[N],a[N];
int main() {
	
	freopen("crystal3.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(LL i=1;i<=n;i++){
		cin>>q[i];
	}
	sort(q+1,q+n+1,cmp);
	for(LL i=1;i<=n;i++){
		a[i]=q[i]-q[i+1]+a[i-1];
	}
	LL res=-1e9;
	
//	for(int i=1;i<=n-1;i++){
//		cout<<a[i]<<" ";
//	}
	
	for(LL i=0;i<=n;i++){
		LL num=0;
		for(LL j=i+1;j<=n;j++){
			
			num+=a[j]-a[i];
			if(num>m){
				break;
			}else{
				res=max(res,j-i+1);
			}
		}
	}
	if(res==-1e9){
		cout<<"1";
	}else{
		cout<<res;
	}
	return 0;
}
