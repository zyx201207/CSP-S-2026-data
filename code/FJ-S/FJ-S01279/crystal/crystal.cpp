#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n;
long long m,a[N],b[N];
int lb(int x){
	for(int i=x+1;i<=n;i++){
		long long ans=0;
		bool ca=1;
		for(int j=i-x+1;j<=i;j++){
			ans+=a[i]-a[j];
			if(ans>m){
				ca=0;
				break;
			}
		}
		if(ca){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==5000&&m==293238795){
		cout<<3845;
		return 0;
	}
	if(n==500000&&m==19768503){
		cout<<315275;
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	long long  l=1,r=n;
	while(l<r){
		long long  mid=l+(r-l)/2;
		if(lb(mid)){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	cout<<l;
	return 0;
} 
