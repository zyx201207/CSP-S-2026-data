#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001];
bool A=1,B=1,T=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) B=0;
		if(i>=2&&a[i]-a[i-1]!=1) A=0;
	}
	if(A){
		if(m>=(n-1)*n/2){
			cout<<n;
			return 0;
		}else{
			long long l=1,r=500000,mid;
			while(T){
				
				mid=(l+r)/2;
				if(mid*mid+mid<=2*m&&(mid+1)*(mid+1)+(mid+1)>2*m){
					cout<<mid+1;
					return 0;
				}else if(mid*mid+mid>2*m){
					r=mid;
					mid=(l+r)/2;
				}else{
					l=mid;
					mid=(l+r)/2;
				}
			}
		}
	}
	if(B){
		long long x=a[2]-a[1];
		if(m>=(n-1)*n/2*x){
			cout<<n;
		}else{
			long long l=1,r=n,mid;
			while(T){
				mid=(l+r)/2;
				if(x*(mid*mid+mid)<=2*m&&x*((mid+1)*(mid+1)+(mid+1))>2*m){
					cout<<mid+1;
					return 0;
				}else if(x*(mid*mid+mid)>2*m){
					r=mid;
					mid=(l+r)/2;
				}else{
					l=mid;
					mid=(l+r)/2;
				}
			}
		}
	}fclose(stdin);
	fclose(stdout);
	return 0;
}
